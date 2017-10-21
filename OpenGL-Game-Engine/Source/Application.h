#pragma once

#include "Window.h"

class Application {
private:
	Window* window;
	float desiredDeltaTime;

	void Run();
	~Application();

public:
	Application(const char* windowName, int width, int height);
};