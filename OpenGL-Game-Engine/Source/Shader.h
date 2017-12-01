#pragma once

#include "Export.h"
#include <include\glm.h>
#include <string>
#include <unordered_map>

class Shader {
private:
	static const std::string&	path;
	static std::unordered_map<std::string, Shader*> loadedShaders;

	std::string name;
	unsigned int vertexShader, fragmentShader, shaderProgram;
	void CompileShaders(const char* vertexSource, const char* fragmentSource);
	unsigned int Compile(unsigned int type, const char* source);

	Shader(const std::string& name, const char* vertexFile, const char* fragmentFile);
	~Shader();

public:
	OPENGL_ENGINE_API static Shader* Load(const std::string& name);
	OPENGL_ENGINE_API static void Unload(Shader* shader);

	void Bind();
	void Unbind();

	void SetUniformMatrix4fv(const char* name, const glm::mat4& matrix);
	void SetUniform1f(const char* name, const float& value);
	void SetUniform2f(const char* name, const glm::vec2& vector);
	void SetUniform3f(const char* name, const glm::vec3& vector);
	void SetUniform4f(const char* name, const glm::vec4& vector);
	void SetUniform1i(const char* name, const int& value);
};