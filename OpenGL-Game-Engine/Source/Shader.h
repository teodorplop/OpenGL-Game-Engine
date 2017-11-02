#pragma once

#include "Export.h"
#include <include\glm.h>

class Shader {
private:
	unsigned int vertexShader, fragmentShader, shaderProgram;
	void CompileShaders(const char* vertexSource, const char* fragmentSource);
	unsigned int Compile(unsigned int type, const char* source);

	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

public:
	OPENGL_ENGINE_API static Shader* Create(const char* vertexFile, const char* fragmentFile);
	OPENGL_ENGINE_API static void Destroy(Shader* shader);

	void Bind();
	void Unbind();

	void SetUniformMatrix4fv(const char* name, const glm::mat4& matrix);
	void SetUniform1f(const char* name, const float& value);
	void SetUniform2f(const char* name, const glm::vec2& vector);
	void SetUniform3f(const char* name, const glm::vec3& vector);
	void SetUniform4f(const char* name, const glm::vec4& vector);
	void SetUniform1i(const char* name, const int& value);
};