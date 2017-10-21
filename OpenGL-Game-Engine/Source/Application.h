#pragma once

#ifdef OPENGL_ENGINE_EXPORTS
#define OPENGL_ENGINE_API __declspec(dllexport)
#else
#define OPENGL_ENGINE_API __declspec(dllimport)
#endif

#include "Window.h"

class Application {
private:
	Window* window;
	float desiredDeltaTime;

	void Run();
	~Application();

public:
	OPENGL_ENGINE_API Application(const char* windowName, int width, int height);
};