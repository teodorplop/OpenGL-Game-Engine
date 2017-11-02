#pragma once

#include <FreeImage.h>
#include "Texture.h"
#include "Color.h"

#include "Export.h"

class Texture2D : public Texture {
	FIBITMAP* pixels;
	int width, height;

	unsigned int textureId;

	void GenerateGLTexture();

public:
	Texture2D(const char* filename);
	Texture2D(int width, int height);

	OPENGL_ENGINE_API static Texture2D* Create(const char* filename);
	OPENGL_ENGINE_API static Texture2D* Create(int width, int height);
	OPENGL_ENGINE_API Color GetPixel(int x, int y);
	OPENGL_ENGINE_API void SetPixel(int x, int y, Color col);

	void Bind(int index = 0);
	void Unbind();
};
