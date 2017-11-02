#pragma once

#include <vector>
#include "Buffer.h"

// VAO
class VertexArray {
private:
	unsigned int arrayID;
	std::vector<Buffer*> buffers;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(Buffer* buffer, unsigned int index);
	void Bind();
	void Unbind();
};