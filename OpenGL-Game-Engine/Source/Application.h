#pragma once

#include "Export.h"

#include "Window.h"

class Application {
private:
	Window* window;
	float desiredDeltaTime;

	void RegisterEngineComponents();

public:
	OPENGL_ENGINE_API Application(const char* windowName, int width, int height, bool fullscreen);
	OPENGL_ENGINE_API void Run();
	OPENGL_ENGINE_API void Quit();
};