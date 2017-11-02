#include "IndexBuffer.h"

#include <include\gl.h>

using namespace std;

IndexBuffer::IndexBuffer(bool dynamic) {
	glGenBuffers(1, &bufferID);
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;
}

IndexBuffer::IndexBuffer(const std::vector<unsigned int>& data, bool dynamic) {
	glGenBuffers(1, &bufferID);
	SetData(data, dynamic);
}

IndexBuffer::~IndexBuffer() {
	glDeleteBuffers(1, &bufferID);
}

void IndexBuffer::SetData(const vector<unsigned int>& data, bool dynamic) {
	count = (int)data.size();
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), &data[0], GL_STATIC_DRAW);
	Unbind();
}

void IndexBuffer::UpdateData(const vector<unsigned int>& data) {
	Bind();
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, count * sizeof(unsigned int), &data[0]);
	Unbind();
}

void IndexBuffer::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void IndexBuffer::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int IndexBuffer::GetCount() {
	return count;
}