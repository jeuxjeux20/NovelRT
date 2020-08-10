#include <jni/string_conversion.hpp>
#include <NovelRT.h>

namespace jni {
  std::u16string convertUTF8ToUTF16(const std::string& string) {
#if defined(WIN32)
    UINT page = CP_UTF8;
    DWORD options = MB_PRECOMPOSED;
    const char* source = string.c_str();
    auto sourceSize = int(string.size());

    int requiredSize = MultiByteToWideChar(page, options, source, sourceSize, nullptr, 0);

    std::vector<wchar_t> resultBuffer(requiredSize);
    if (!MultiByteToWideChar(page, options, source, sourceSize, resultBuffer.data(), requiredSize)) {
      throw new std::runtime_error("Failed to convert an UTF8 string to UTF16. "
                                   "Windows error code: " + std::to_string(GetLastError()));
    }

    std::wstring wideString(resultBuffer.data());
    return std::u16string(wideString.begin(), wideString.end());
#endif
    // TODO: Other platforms support
  }

  std::string convertUTF16ToUTF8(const std::u16string& string) {
#if defined(WIN32)
    UINT page = CP_UTF8;
    DWORD options = MB_PRECOMPOSED;
    const wchar_t* source = reinterpret_cast<const wchar_t*>(string.c_str());
    auto sourceSize = int(string.size());

    int requiredSize = WideCharToMultiByte(page, options, source, sourceSize, nullptr, 0, NULL, NULL);

    std::vector<char> resultBuffer(requiredSize);
    if (!WideCharToMultiByte(page, options, source, sourceSize, resultBuffer.data(), requiredSize, NULL, NULL)) {
      throw new std::runtime_error("Failed to convert an UTF16 string to UTF18. "
                                   "Windows error code: " + std::to_string(GetLastError()));
    }

    return std::string(resultBuffer.data());
#endif
    // TODO: Other platforms support
  }
}
