#include "Shader.h"
#include "Utils/FileIO.h"

#include <include\gl.h>
#include "Light.h"

#include <filesystem>

using namespace std;

unordered_map<string, Shader*> Shader::loadedShaders;
unordered_map<string, string> Shader::includeShaders;
const string& Shader::includePath = "Dependencies/Shaders/";
const string& Shader::path = "Assets/Shaders/";

Shader* Shader::Load(const string& name) {
	auto it = loadedShaders.find(name);
	if (it == loadedShaders.end()) {
		string vertFilePath = path + name + ".vert";
		string fragFilePath = path + name + ".frag";
		const char* vertFile = vertFilePath.c_str();
		const char* fragFile = fragFilePath.c_str();

		Shader* shader = new Shader(name, vertFile, fragFile);
		loadedShaders.insert({ name, shader });
		return shader;
	}
	return it->second;
}

void Shader::Unload(Shader* shader) {
	loadedShaders.erase(shader->name);
	delete shader;
}

GLuint Shader::Compile(GLuint type, const char* source) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		GLchar infoLog[1024];
		glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", type, infoLog);
	}

	return shader;
}

void Shader::CompileShaders(const char* vertexSource, const char* fragmentSource) {
	vertexShader = Compile(GL_VERTEX_SHADER, vertexSource);
	fragmentShader = Compile(GL_FRAGMENT_SHADER, fragmentSource);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	GLint success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar errorLog[1024];
		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", errorLog);
	}

	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::Shader(const string& name, const char* vertexFile, const char* fragmentFile) {
	this->name = name;

	string vertexCode = FileIO::GetFileContents(vertexFile);
	string fragmentCode = FileIO::GetFileContents(fragmentFile);
	IncludeShaders(vertexCode);
	IncludeShaders(fragmentCode);
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	CompileShaders(vertexSource, fragmentSource);
}

void Shader::IncludeShaders(string& source) {
	size_t start = source.find("#include");
	size_t idx = start;
	while (idx != string::npos) {
		while (idx < source.size() && source[idx] != '\"')
			++idx;
		++idx;

		string filePath = includePath;
		while (idx < source.size() && source[idx] != '\"')
			filePath += source[idx++];

		if (idx >= source.size())
			return;

		source.erase(start, idx - start + 1);

		auto it = includeShaders.find(filePath);
		if (it == includeShaders.end()) {
			string content = FileIO::GetFileContents(filePath.c_str());
			includeShaders.insert({ filePath, content });
			source.insert(start, content);
		} else
			source.insert(start, it->second);

		start = source.find("#include");
		idx = start;
	}
}

Shader::~Shader() {
	glDeleteProgram(shaderProgram);
}

void Shader::Bind() {
	glUseProgram(shaderProgram);
}
void Shader::Unbind() {
	glUseProgram(0);
}

void Shader::SetUniformMatrix4fv(const char* name, const glm::mat4& matrix) {
	GLint matrixID = glGetUniformLocation(shaderProgram, name);
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &matrix[0][0]);
}
void Shader::SetUniform3f(const char* name, const glm::vec3& vector) {
	GLint vectorID = glGetUniformLocation(shaderProgram, name);
	glUniform3f(vectorID, vector.x, vector.y, vector.z);
}
void Shader::SetUniform4f(const char* name, const glm::vec4& vector) {
	GLint vectorID = glGetUniformLocation(shaderProgram, name);
	glUniform4f(vectorID, vector.x, vector.y, vector.z, vector.w);
}
void Shader::SetUniform1f(const char* name, const float& value) {
	GLint floatID = glGetUniformLocation(shaderProgram, name);
	glUniform1f(floatID, value);
}
void Shader::SetUniform2f(const char* name, const glm::vec2& vector) {
	GLint vectorID = glGetUniformLocation(shaderProgram, name);
	glUniform2f(vectorID, vector.x, vector.y);
}
void Shader::SetUniform1i(const char* name, const int& value) {
	GLint intID = glGetUniformLocation(shaderProgram, name);
	glUniform1i(intID, value);
}
void Shader::SetUniformColor(const char* name, const Color& color) {
	GLint intID = glGetUniformLocation(shaderProgram, name);
	glUniform4f(intID, color.r, color.g, color.b, color.a);
}

void Shader::SetGlobal3f(const char* name, const glm::vec3& vector) {
	for (auto& it : loadedShaders) {
		it.second->Bind();
		it.second->SetUniform3f(name, vector);
		it.second->Unbind();
	}
}

void Shader::SetGlobalLights(const char* name, const vector<Light*> lights) {
	for (auto& it : loadedShaders) {
		it.second->Bind();

		string str = name;
		str += "_Length";
		it.second->SetUniform1i(str.c_str(), (int)lights.size());

		for (int i = 0; i < lights.size(); ++i) {
			string str = name;
			str += "[" + to_string(i) + "].";

			string uniform = str + "position";
			it.second->SetUniform4f(uniform.c_str(), lights[i]->GetPosition());

			uniform = str + "color";
			it.second->SetUniformColor(uniform.c_str(), lights[i]->GetColor());
		}

		it.second->Unbind();
	}
}