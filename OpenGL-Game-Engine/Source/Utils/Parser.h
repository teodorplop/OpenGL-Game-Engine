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

	OPENGL_ENGINE_API static int StringToInt(const std::string& text);
	OPENGL_ENGINE_API static float StringToFloat(const std::string& text);
	OPENGL_ENGINE_API static glm::vec2 StringToVec2(const std::string& text);
	OPENGL_ENGINE_API static glm::vec3 StringToVec3(const std::string& text);
	OPENGL_ENGINE_API static glm::vec4 StringToVec4(const std::string& text);
	OPENGL_ENGINE_API static Color StringToColor(const std::string& text);
};
