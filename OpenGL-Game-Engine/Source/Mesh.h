#pragma once

#include "Export.h"

#include <include\glm.h>
#include <vector>

#include "Buffers\Buffer.h"
#include "Buffers\VertexArray.h"
#include "Buffers\IndexBuffer.h"
#include "Color.h"

class Mesh {
	static const std::string& path;

	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> normals;
	std::vector<Color> colors;
	std::vector<glm::vec2> uvs;
	std::vector<unsigned int> indices;

	Buffer *vertexBuffer, *normalBuffer, *colorBuffer, *uvBuffer;
	VertexArray* vao;
	IndexBuffer* indexBuffer;

	void GenerateGLMesh();

	Mesh();
	void Bind();
	void Unbind();

public:
	void Draw();

	OPENGL_ENGINE_API static Mesh* Create();
	OPENGL_ENGINE_API static Mesh* Load(const std::string& filename);

	OPENGL_ENGINE_API void SetVertices(std::vector<glm::vec3> vertices);
	OPENGL_ENGINE_API void SetVertices(std::vector<glm::vec4> vertices);
	OPENGL_ENGINE_API void SetNormals(std::vector<glm::vec3> normals);
	OPENGL_ENGINE_API void SetColors(std::vector<Color> colors);
	OPENGL_ENGINE_API void SetUV(std::vector<glm::vec2> uvs);
	OPENGL_ENGINE_API void SetIndices(std::vector<unsigned int> indices);

	OPENGL_ENGINE_API void Clear();
};
