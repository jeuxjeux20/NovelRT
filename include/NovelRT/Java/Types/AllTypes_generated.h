#ifndef NOVELRT_JAVA_GENERATED_TYPES
#define NOVELRT_JAVA_GENERATED_TYPES

// This file is auto-generated by the code-generation module.
//
// Any changes made to this file will be ignored after a rebuild of
// the core NovelRT Java library.

#include "Type.h"

namespace NovelRT::Java::Types {
  struct SceneConstructionRequestedListener : public Type<SceneConstructionRequestedListener> {
    static constexpr auto Name() {
      return "com/github/novelrt/event/SceneConstructionRequestedListener";
    }
    
    static inline MethodDef<void()> listen{"listen"};
  };
  
  struct RGBAColour : public Type<RGBAColour> {
    static constexpr auto Name() {
      return "com/github/novelrt/graphics/RGBAColour";
    }
    
    static inline MethodDef<jni::jint()> asRGBA{"asRGBA"};
    static inline ConstructorDef<jni::jint, jni::jint, jni::jint, jni::jint> mainConstructor;
    static inline ConstructorDef<jni::jint> rgbaConstructor;
  };
  
  struct HandleObject : public Type<HandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/internal/handle/HandleObject";
    }
    
    static inline MethodDef<jni::jlong()> getHandle{"getHandle"};
  };
  
  struct Path : public Type<Path> {
    static constexpr auto Name() {
      return "java/nio/file/Path";
    }
  };
  
  struct Vector2 : public Type<Vector2> {
    static constexpr auto Name() {
      return "com/github/novelrt/maths/Vector2";
    }
    
    static inline FieldDef<jni::jfloat> x{"x"};
    static inline FieldDef<jni::jfloat> y{"y"};
    static inline ConstructorDef<jni::jfloat, jni::jfloat> mainConstructor;
    static inline ConstructorDef<> mainConstructor_1;
  };
  
  struct NovelRTLoader : public Type<NovelRTLoader> {
    static constexpr auto Name() {
      return "com/github/novelrt/NovelRTLoader";
    }
    
    static inline StaticFieldDef<jni::jboolean> hasBeenLoaded{"hasBeenLoaded"};
  };
  
  struct OwnedHandleObject : public Type<OwnedHandleObject>, Super<HandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/internal/handle/OwnedHandleObject";
    }
    
    static inline MethodDef<void()> invalidate{"invalidate"};
  };
  
  struct UnownedHandleObject : public Type<UnownedHandleObject>, Super<HandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/internal/handle/UnownedHandleObject";
    }
  };
  
  struct NativeHelpers : public Type<NativeHelpers> {
    static constexpr auto Name() {
      return "com/github/novelrt/internal/NativeHelpers";
    }
    
    static inline StaticMethodDef<jni::Object<jni::StringTag>(jni::Object<Path>)> toNativeString{"toNativeString"};
  };
  
  struct Transform : public Type<Transform>, Super<OwnedHandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/maths/Transform";
    }
    
    static inline ConstructorDef<jni::jlong, jni::jboolean> mainConstructor;
  };
  
  struct WorldObject : public Type<WorldObject>, Super<OwnedHandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/WorldObject";
    }
  };
  
  struct NovelRunner : public Type<NovelRunner>, Super<OwnedHandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/NovelRunner";
    }
  };
  
  struct Event : public Type<Event>, Super<UnownedHandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/event/Event";
    }
  };
  
  struct RenderingService : public Type<RenderingService>, Super<UnownedHandleObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/graphics/RenderingService";
    }
    
    static inline ConstructorDef<jni::jlong> mainConstructor;
  };
  
  struct RenderObject : public Type<RenderObject>, Super<WorldObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/graphics/RenderObject";
    }
    
    static inline ConstructorDef<jni::jlong, jni::jboolean> mainConstructor;
  };
  
  struct SceneConstructionRequestedEvent : public Type<SceneConstructionRequestedEvent>, Super<Event> {
    static constexpr auto Name() {
      return "com/github/novelrt/event/SceneConstructionRequestedEvent";
    }
    
    static inline ConstructorDef<jni::jlong> mainConstructor;
  };
  
  struct TextRect : public Type<TextRect>, Super<RenderObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/graphics/TextRect";
    }
    
    static inline ConstructorDef<jni::jlong, jni::jboolean> mainConstructor;
  };
  
  struct BasicRect : public Type<BasicRect>, Super<RenderObject> {
    static constexpr auto Name() {
      return "com/github/novelrt/graphics/BasicRect";
    }
    
    static inline ConstructorDef<jni::jlong, jni::jboolean> mainConstructor;
  };
}
#endif