#pragma once

#include "Export.h"

#include "Window.h"

class Application {
private:
	Window* window;
	float desiredDeltaTime;

	void Run();
	~Application();

public:
	OPENGL_ENGINE_API Application(const char* windowName, int width, int height, bool fullscreen);
};