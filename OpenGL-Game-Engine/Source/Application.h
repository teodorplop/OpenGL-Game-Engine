#pragma once

#include "Export.h"

#include "Window.h"

class Application {
private:
	Window* window;
	float desiredDeltaTime;

	Application(const char* windowName, int width, int height, bool fullscreen);

public:
	OPENGL_ENGINE_API static Application* Create(const char* windowName, int width, int height, bool fullscreen);
	OPENGL_ENGINE_API void Run();
	OPENGL_ENGINE_API void Quit();
};