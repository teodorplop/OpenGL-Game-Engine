#pragma once

#include <include\gl.h>

class Texture;

class WaterFrameBuffer {
private:
	static const int reflectionWidth, reflectionHeight;
	static const int refractionWidth, refractionHeight;

	GLuint reflectionFrameBuffer, reflectionDepthBuffer;
	GLuint refractionFrameBuffer;
	Texture *reflectionTexture, *refractionTexture, *refractionDepthTexture;

	GLuint CreateFrameBuffer();
	GLuint CreateDepthBufferAttachment(int width, int height);
	void BindFrameBuffer(GLuint buffer, int width, int height);

public:
	WaterFrameBuffer();
	~WaterFrameBuffer();

	void Clear();
	void BindReflectionBuffer();
	void BindRefractionBuffer();
	void UnbindBuffer();
	Texture* GetReflectionTexture();
	Texture* GetRefractionTexture();
	Texture* GetRefractionDepthTexture();
};