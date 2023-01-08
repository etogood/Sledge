#pragma once

#ifdef SL_PLATFORM_WINDOWS
    #ifdef SL_BUILD_DLL
        #define SLEDGE_API __declspec(dllexport)
    #else
        #define SLEDGE_API __declspec(dllimport)
    #endif
#else
    #error Sledge only supports Windows!
#endif