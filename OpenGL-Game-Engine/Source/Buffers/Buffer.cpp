#include "Buffer.h"

#include <include\gl.h>

using namespace std;

Buffer::Buffer(bool dynamic) {
	glGenBuffers(1, &bufferID);
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;
}
template <typename T>
Buffer::Buffer(const vector<T>& data, int componentCount, bool dynamic) {
	glGenBuffers(1, &bufferID);
	SetData(data, componentCount, dynamic);
}
Buffer::~Buffer() {
	glDeleteBuffers(1, &bufferID);
}

template <typename T>
void Buffer::SetData(const vector<T>& data, int componentCount, bool dynamic) {
	this->componentCount = componentCount;
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), &data[0], usage);
	Unbind();
}

template <typename T>
void Buffer::UpdateData(const vector<T>& data) {
	Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * sizeof(T), &data[0]);
	Unbind();
}

void Buffer::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

void Buffer::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int Buffer::GetComponentCount() {
	return componentCount;
}