#pragma once

class Texture {
protected:
	unsigned int textureId;

public:
	unsigned int GetTextureId() const;

	virtual void Bind(int index = 0) = 0;
	virtual void Unbind() = 0;
};