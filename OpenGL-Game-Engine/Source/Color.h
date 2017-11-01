#pragma once

#include "Export.h"

struct Color {
	OPENGL_ENGINE_API static Color black, gray, white, red, green, blue, yellow;

	unsigned char r, g, b, a;

	OPENGL_ENGINE_API Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
};