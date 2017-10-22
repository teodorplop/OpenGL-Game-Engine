#pragma once

#ifdef OPENGL_ENGINE_EXPORTS
#define OPENGL_ENGINE_API __declspec(dllexport)
#else
#define OPENGL_ENGINE_API __declspec(dllimport)
#endif