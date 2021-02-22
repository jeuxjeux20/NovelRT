package com.github.novelrt

import com.github.novelrt.codegeneration.annotations.GenerateNative

@GenerateNative
object NovelRTLoader {
  private const val DEFAULT_LIBRARY_NAME = "Engine"
  @JvmStatic
  @GenerateNative
  private var hasBeenLoaded = false

  @Synchronized
  fun load(libraryName: String = DEFAULT_LIBRARY_NAME) {
    if (!hasBeenLoaded) {
      System.loadLibrary(libraryName)
      hasBeenLoaded = true
    }
  }
}
