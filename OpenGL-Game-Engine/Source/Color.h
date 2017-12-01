#pragma once

#include "Export.h"
#include <iostream>
#include <string>

struct Color {
	OPENGL_ENGINE_API static Color black, gray, white, red, green, blue, yellow;

	float r, g, b, a;

	OPENGL_ENGINE_API Color();
	OPENGL_ENGINE_API Color(float r, float g, float b, float a = 1);
};

OPENGL_ENGINE_API std::ostream& operator<<(std::ostream& out, const Color& color);