#pragma once

#include "Export.h"

#include <include\glm.h>
#include <vector>

class Mesh {
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<unsigned int> indices;

	bool isDirty;

public:
	OPENGL_ENGINE_API void SetVertices(std::vector<glm::vec3> vertices);
	OPENGL_ENGINE_API void SetNormals(std::vector<glm::vec3> normals);
	OPENGL_ENGINE_API void SetUV(std::vector<glm::vec2> uvs);
	OPENGL_ENGINE_API void SetIndices(std::vector<unsigned int> indices);

	OPENGL_ENGINE_API void Clear();
};
