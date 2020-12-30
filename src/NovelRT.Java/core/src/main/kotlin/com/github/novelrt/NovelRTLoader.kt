package com.github.novelrt

object NovelRTLoader {
  private const val DEFAULT_LIBRARY_NAME = "Engine"
  private var hasBeenLoaded = false

  @Synchronized
  fun load(libraryName: String = DEFAULT_LIBRARY_NAME) {
    if (!hasBeenLoaded) {
      System.loadLibrary(libraryName)
      hasBeenLoaded = true
    }
  }
}
