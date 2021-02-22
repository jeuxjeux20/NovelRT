package com.github.novelrt.codegeneration.cpp

import com.github.novelrt.codegeneration.CodeGenOptions
import com.github.novelrt.codegeneration.model.*
import com.github.novelrt.codegeneration.util.getDirectAncestor
import java.util.*
import javax.annotation.processing.ProcessingEnvironment
import javax.lang.model.element.ExecutableElement
import javax.lang.model.element.Modifier
import javax.lang.model.type.TypeKind
import javax.lang.model.type.TypeMirror

class FinalFileWriter(
  private val cppWriter: CppWriter,
  private val processingEnv: ProcessingEnvironment,
  private val codeGenerationModel: CodeGenerationModel,
  private val codeGenOptions: CodeGenOptions
) {
  private val typeResolver = CppTypeResolver(codeGenerationModel)

  fun write(types: List<DefinedGenerationType> = codeGenerationModel.getDefinedTypesByReferenceOrder()) {
    cppWriter.beginIncludeGuard("NOVELRT_JAVA_GENERATED_TYPES")
    cppWriter.writeLine()

    cppWriter.writeLine("// This file is auto-generated by the code-generation module.")
    cppWriter.writeLine("//")
    cppWriter.writeLine("// Any changes made to this file will be ignored after a rebuild of")
    cppWriter.writeLine("// the core NovelRT Java library.")
    cppWriter.writeLine()

    codeGenOptions.includeDirectives.forEach(cppWriter::declareInclude)
    cppWriter.writeLine()

    cppWriter.beginNamespace("NovelRT::Java::Types")

    for (type in types) {
      val cppSuperTypes = getCppSuperTypes(type)

      cppWriter.beginStruct(type.cppName, cppSuperTypes)

      cppWriter.beginMethod(
        "Name",
        returnType = "auto",
        modifiers = EnumSet.of(CppModifier.CONSTEXPR, CppModifier.STATIC)
      )

      val erasedType = processingEnv.typeUtils.erasure(type.javaType)
      cppWriter.writeLine("return \"${erasedType.toString().replace('.', '/')}\";")

      cppWriter.endMethod()
      if (type.allMembers.isNotEmpty()) {
        cppWriter.writeLine()
      }

      for (member in type.allMembers) {
        when (member) {
          is GenerationMethod -> writeMethodField(member)
          is GenerationField -> writeFieldField(member)
          is GenerationConstructor -> writeConstructorField(member)
        }
      }

      cppWriter.endStruct()

      if (type != types.last()) {
        cppWriter.writeLine()
      }
    }

    cppWriter.endNamespace()
    cppWriter.endIncludeGuard()
  }

  private fun writeMethodField(member: GenerationMethod) {
    val isStatic = member.javaElement.modifiers.contains(Modifier.STATIC)
    val definitionType = if (isStatic) "StaticMethodDef" else "MethodDef"

    val signature = getCppMethodSignature(member.javaElement)

    cppWriter.declareField(
      name = member.fieldName,
      type = "$definitionType<$signature>",
      modifiers = MEMBER_FIELD_MODIFIERS,
      initializerArguments = listOf('"' + member.fieldName + '"')
    )
  }

  private fun writeFieldField(member: GenerationField) {
    val isStatic = member.javaElement.modifiers.contains(Modifier.STATIC)
    val definitionType = if (isStatic) "StaticFieldDef" else "FieldDef"

    val resolvedFieldType = resolveAsObjectWrapped(member.javaElement.asType())

    cppWriter.declareField(
      name = member.fieldName,
      type = "$definitionType<$resolvedFieldType>",
      modifiers = MEMBER_FIELD_MODIFIERS,
      initializerArguments = listOf('"' + member.fieldName + '"')
    )
  }

  private fun writeConstructorField(member: GenerationConstructor) {
    val resolvedArgList = resolveArgList(member.javaElement)

    cppWriter.declareField(
      name = member.fieldName,
      type = "ConstructorDef<$resolvedArgList>",
      modifiers = MEMBER_FIELD_MODIFIERS
    )
  }

  private fun getCppSuperTypes(type: DefinedGenerationType): List<String> {
    val superTypes = mutableListOf<String>()
    superTypes.add("Type<${typeResolver.resolve(type.javaType)}>")

    val superType = processingEnv.typeUtils.getDirectAncestor(type.javaType)
    // Make sure that the type has been explicitly marked as generated
    // so we don't spit out the entire class hierarchy for every single type.
    if (superType.toString() != Any::class.java.canonicalName &&
      codeGenerationModel.getType(superType) != null
    ) {
      superTypes.add("Super<${typeResolver.resolve(superType)}>")
    }

    return superTypes
  }

  private fun getCppMethodSignature(method: ExecutableElement): String {
    val resolvedReturnType = resolveAsObjectWrapped(method.returnType)
    val resolvedArgs = resolveArgList(method)

    return "$resolvedReturnType($resolvedArgs)"
  }

  private fun resolveArgList(method: ExecutableElement) =
    method.parameters.joinToString { resolveAsObjectWrapped(it.asType()) }

  private fun resolveAsObjectWrapped(typeMirror: TypeMirror): String {
    val resolved = typeResolver.resolve(typeMirror)
    return if (typeMirror.kind == TypeKind.DECLARED) {
      "jni::Object<$resolved>"
    }
    else {
      resolved
    }
  }

  companion object {
    private val MEMBER_FIELD_MODIFIERS = EnumSet.of(CppModifier.STATIC, CppModifier.INLINE)
  }
}
