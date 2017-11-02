#include "Texture2D.h"
#include "Utils/TextureUtils.h"

#include<cstdio>
#include<include\gl.h>

Texture2D* Texture2D::Create(const char* filename) {
	return new Texture2D(filename);
}

Texture2D* Texture2D::Create(int width, int height) {
	return new Texture2D(width, height);
}

Texture2D::Texture2D(const char* filename) {
	this->pixels = TextureUtils::Load_Texture(filename);
	this->width = FreeImage_GetWidth(pixels), this->height = FreeImage_GetHeight(pixels);

	GenerateGLTexture();
}

Texture2D::Texture2D(int width, int height) {
	this->width = width, this->height = height;
	pixels = FreeImage_Allocate(width, height, 32);

	GenerateGLTexture();
}

void Texture2D::GenerateGLTexture() {
	glGenTextures(1, &textureId);
	Bind();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, FreeImage_GetBits(pixels));
	//glGenerateMipmap(GL_TEXTURE_2D);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	Unbind();
}

Color Texture2D::GetPixel(int x, int y) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		fprintf(stderr, "GetPixel(%d, %d) out of range.", x, y);
		return Color::black;
	}

	RGBQUAD pixel;
	if (!FreeImage_GetPixelColor(pixels, x, y, &pixel))
		fprintf(stderr, "Could not get pixel color.");

	return Color((float)pixel.rgbRed / 255, (float)pixel.rgbGreen / 255, (float)pixel.rgbBlue / 255, (float)pixel.rgbReserved / 255);
}

void Texture2D::SetPixel(int x, int y, Color col) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		fprintf(stderr, "SetPixel(%d, %d) out of range.", x, y);
		return;
	}

	RGBQUAD pixel;
	pixel.rgbRed = (BYTE)(col.r * 255);
	pixel.rgbGreen = (BYTE)(col.g * 255);
	pixel.rgbBlue = (BYTE)(col.b * 255);
	pixel.rgbReserved = (BYTE)(col.a * 255);

	if (!FreeImage_SetPixelColor(pixels, x, y, &pixel)) {
		fprintf(stderr, "Could not set pixel color.");
		return;
	}
}

void Texture2D::Bind(int index) {
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture2D::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}