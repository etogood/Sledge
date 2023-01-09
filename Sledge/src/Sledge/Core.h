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

#ifdef SL_ENABLE_ASSERTS
    #define SL_ASSERT(x, ...) { if(!(x)) { SL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define SL_CORE_ASSERT(x, ...) { if(!(x)) { SL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define SL_ASSERT(x, ...)
    #define SL_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << (x))
