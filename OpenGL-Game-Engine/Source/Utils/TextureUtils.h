#pragma once

#include <FreeImage.h>

class TextureUtils {
public:
	static FIBITMAP* Load_Texture(const char* filename);
	static void Unload_Texture(FIBITMAP* image);
};