#include "Texture.h"

using namespace std;

const string& Texture::path = "Assets/Textures/";

unsigned int Texture::GetTextureId() const {
	return textureId;
}