#pragma once

#include "Export.h"
#include <include\glm.h>
#include <string>
#include <unordered_map>
#include <vector>

class Light;
struct Color;

class Shader {
private:
	static const std::string&	path;
	static const std::string& includePath;
	static std::unordered_map<std::string, Shader*> loadedShaders;
	static std::unordered_map<std::string, std::string> includeShaders;

	static void IncludeShaders(std::string& source);

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
	void SetUniformColor(const char* name, const Color& color);
	void SetUniform1i(const char* name, const int& value);

	OPENGL_ENGINE_API static void SetGlobal1f(const char* name, const float& value);
	OPENGL_ENGINE_API static void SetGlobal3f(const char* name, const glm::vec3& vector);
	OPENGL_ENGINE_API static void SetGlobal4f(const char* name, const glm::vec4& vector);
	// king of ugly but... meh.
	static void SetGlobalLights(const char* name, const std::vector<Light*> lights);
};
