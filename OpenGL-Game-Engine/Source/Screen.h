#pragma once

#include "Export.h"
#include "Window.h"
#include <include\glm.h>

class Screen {
	static Window* window;

public:
	static void Handle(Window* window);

	OPENGL_ENGINE_API static int GetWidth();
	OPENGL_ENGINE_API static int GetHeight();
	OPENGL_ENGINE_API static void SetResolution(int width, int height);
	OPENGL_ENGINE_API static void EnableCursor(bool enabled);
};