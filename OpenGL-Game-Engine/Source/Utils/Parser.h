#pragma once

#include "..\Export.h"

#include <string>
#include <include\glm.h>
#include "..\Color.h"

class Parser {
private:
	std::string text;
	std::string::size_type idx;

public:
	OPENGL_ENGINE_API static Parser* Create(const std::string& text);
	OPENGL_ENGINE_API static void Destroy(Parser* parser);

	OPENGL_ENGINE_API int NextInt();
	OPENGL_ENGINE_API float NextFloat();
	OPENGL_ENGINE_API glm::vec2 NextVec2();
	OPENGL_ENGINE_API glm::vec3 NextVec3();
	OPENGL_ENGINE_API glm::vec4 NextVec4();
	OPENGL_ENGINE_API Color NextColor();
	OPENGL_ENGINE_API std::string NextWord();
};
