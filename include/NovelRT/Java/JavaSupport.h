#ifndef NOVELRT_JAVASUPPORT_H
#define NOVELRT_JAVASUPPORT_H

// Base stuff
#include "EssentialIncludes.h"
#include "Init.h"

#include "Types.h"
#include "Bindings.h"
#include "TypeConversion.h"

#include "Handles.h"

#define MAKE_NATIVE_METHOD(name) jni::MakeNativeMethod<decltype(name), &##name>(name)
#endif //NOVELRT_JAVASUPPORT_H
