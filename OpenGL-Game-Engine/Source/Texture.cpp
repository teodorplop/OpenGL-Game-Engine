#include "Texture.h"
#include "Texture2D.h"
#include <include\gl.h>

using namespace std;

const string& Texture::path = "Assets/Textures/";

unsigned int Texture::GetTextureId() const {
	return textureId;
}
