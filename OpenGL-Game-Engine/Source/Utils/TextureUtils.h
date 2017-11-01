#pragma once

#include <FreeImage.h>

class TextureUtils {
public:
	static BYTE* Load_Texture(const char* filename, int* width, int* height);
	static FIBITMAP* Load_Texture(const char* filename);
	static void Unload_Texture(FIBITMAP* image);
};