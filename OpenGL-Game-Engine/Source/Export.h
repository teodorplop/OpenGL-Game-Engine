#pragma once

#if defined(_WIN32)
    #ifdef OPENGL_ENGINE_EXPORTS
        #define OPENGL_ENGINE_API __declspec(dllexport)
    #else
        #define OPENGL_ENGINE_API __declspec(dllimport)
    #endif
#else
    // DEFINITELY EMPTY
    #define OPENGL_ENGINE_API 
#endif