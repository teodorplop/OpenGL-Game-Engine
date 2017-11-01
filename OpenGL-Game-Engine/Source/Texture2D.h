#pragma once

#include <FreeImage.h>
#include "Color.h"

class Texture2D {
	FIBITMAP* pixels;
	int width, height;

public:
	Texture2D(int width, int height);
	Color GetPixel(int x, int y);
	void SetPixel(int x, int y, Color col);
};
