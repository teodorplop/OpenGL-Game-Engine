#include "TextureUtils.h"
#include <cstdio>

FIBITMAP* TextureUtils::Load_Texture(const char* filename) {
	FREE_IMAGE_FORMAT format = FIF_UNKNOWN;

	format = FreeImage_GetFileType(filename, 0);
	if (format == -1) {
		fprintf(stderr, "Could not find image: %s\n", filename);
		return NULL;
	}

	if (format == FIF_UNKNOWN) {
		fprintf(stderr, "Couldn't determine file format - attempting to get from file extension...\n");
		format = FreeImage_GetFIFFromFilename(filename);
		if (format == FIF_UNKNOWN) {
			fprintf(stderr, "Couldn't determine file format.\n");
			return NULL;
		}
	}
	if (!FreeImage_FIFSupportsReading(format)) {
		fprintf(stderr, "Detected image format cannot be read!\n");
		return NULL;
	}

	FIBITMAP* bitmap = FreeImage_Load(format, filename);
	if (!bitmap) {
		fprintf(stderr, "Could not get image bitmap.\n");
		return NULL;
	}

	int bitsPerPixel = FreeImage_GetBPP(bitmap);
	FIBITMAP* bitmap32;
	if (bitsPerPixel == 32) {
		bitmap32 = bitmap;
	} else {
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
		FreeImage_Unload(bitmap);
	}

	return bitmap32;
}

void TextureUtils::Unload_Texture(FIBITMAP* image) {
	FreeImage_Unload(image);
}