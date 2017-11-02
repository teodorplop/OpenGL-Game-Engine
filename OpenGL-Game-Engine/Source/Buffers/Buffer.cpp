#include "Buffer.h"

#include <include\gl.h>

using namespace std;
using namespace glm;

Buffer::Buffer(const vector<float>& data, bool dynamic) {
	glGenBuffers(1, &bufferID);
	SetData(data, dynamic);
}
Buffer::Buffer(const vector<vec2>& data, bool dynamic) {
	glGenBuffers(1, &bufferID);
	SetData(data, dynamic);
}
Buffer::Buffer(const vector<vec3>& data, bool dynamic) {
	glGenBuffers(1, &bufferID);
	SetData(data, dynamic);
}
Buffer::Buffer(const vector<vec4>& data, bool dynamic) {
	glGenBuffers(1, &bufferID);
	SetData(data, dynamic);
}
Buffer::Buffer(const vector<Color>& data, bool dynamic) {
	glGenBuffers(1, &bufferID);
	SetData(data, dynamic);
}
Buffer::~Buffer() {
	glDeleteBuffers(1, &bufferID);
}

void Buffer::SetData(const vector<float>& data, bool dynamic) {
	this->componentCount = 1;
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], usage);
	Unbind();
}

void Buffer::SetData(const vector<vec2>& data, bool dynamic) {
	this->componentCount = 2;
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(vec2), &data[0], usage);
	Unbind();
}

void Buffer::SetData(const vector<vec3>& data, bool dynamic) {
	this->componentCount = 3;
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(vec3), &data[0], usage);
	Unbind();
}

void Buffer::SetData(const vector<vec4>& data, bool dynamic) {
	this->componentCount = 4;
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(vec4), &data[0], usage);
	Unbind();
}

void Buffer::SetData(const vector<Color>& data, bool dynamic) {
	this->componentCount = 4;
	usage = dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(Color), &data[0], usage);
	Unbind();
}

void Buffer::UpdateData(const vector<float>& data) {
	Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * sizeof(float), &data[0]);
	Unbind();
}

void Buffer::UpdateData(const vector<vec2>& data) {
	Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * sizeof(vec2), &data[0]);
	Unbind();
}

void Buffer::UpdateData(const vector<vec3>& data) {
	Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * sizeof(vec3), &data[0]);
	Unbind();
}

void Buffer::UpdateData(const vector<vec4>& data) {
	Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * sizeof(vec4), &data[0]);
	Unbind();
}

void Buffer::UpdateData(const vector<Color>& data) {
	Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, data.size() * sizeof(Color), &data[0]);
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