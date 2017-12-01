#pragma once

#include <string>

class Texture {
protected:
	unsigned int textureId;

	static const std::string& path;

public:
	unsigned int GetTextureId() const;

	virtual void Bind(int index = 0) = 0;
	virtual void Unbind() = 0;
};