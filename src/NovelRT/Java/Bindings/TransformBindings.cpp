#include "NovelRT/Java/JavaSupport.h"
#include "NovelRT/Java/Bindings/Utilities.h"
#include "NovelRT/Java/Bindings/TransformBindings.h"

namespace NovelRT::Java::Bindings {
  using Self = Types::Transform;

  jni::jlong createTransform(jni::JNIEnv& env, Self::Class&,
                             jni::Object<Types::Vector2>& position, jni::Object<Types::Vector2>& scale,
                             jni::jfloat rotation) {
    TypeConversion::Vector2Converter vector2Converter;

    return Handles::toJava(
      new Transform(vector2Converter.fromJava(env, position), rotation,
                    vector2Converter.fromJava(env, scale))
    );
  }

  void deleteTransform(jni::JNIEnv&, Self::Class&, jni::jlong handle) {
    delete Handles::get<Transform>(handle);
  }

  void registerTransformBindings(jni::JNIEnv& env) {
    bindProperty<Self, Types::Vector2, FieldProperty<&Transform::position>>(env, "position");
    bindProperty<Self, Types::Vector2, FieldProperty<&Transform::scale>>(env, "scale");
    bindProperty<Self, jni::jfloat, FieldProperty<&Transform::rotation>>(env, "rotation");

    jni::RegisterNatives(env, *Self::javaClass(),
                         jni::MakeNativeMethod<decltype(createTransform), &createTransform>("createTransform"),
                         jni::MakeNativeMethod<decltype(deleteTransform), &deleteTransform>("deleteTransform"));
  }
}
