#include "Texture2D.h"

#include<cstdio>

Texture2D::Texture2D(int width, int height) {
	this->width = width, this->height = height;
	pixels = FreeImage_Allocate(width, height, 32);
}

Color Texture2D::GetPixel(int x, int y) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		fprintf(stderr, "GetPixel(%d, %d) out of range.", x, y);
		return Color::black;
	}

	RGBQUAD pixel;
	if (!FreeImage_GetPixelColor(pixels, x, y, &pixel))
		fprintf(stderr, "Could not get pixel color.");

	return Color(pixel.rgbRed, pixel.rgbGreen, pixel.rgbBlue, pixel.rgbReserved);
}

void Texture2D::SetPixel(int x, int y, Color col) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		fprintf(stderr, "SetPixel(%d, %d) out of range.", x, y);
		return;
	}

	RGBQUAD pixel;
	pixel.rgbRed = col.r;
	pixel.rgbGreen = col.g;
	pixel.rgbBlue = col.b;
	pixel.rgbReserved = col.a;

	if (!FreeImage_SetPixelColor(pixels, x, y, &pixel))
		fprintf(stderr, "Could not set pixel color.");
}