#include "Material.h"

using namespace std;
using namespace glm;

Material* Material::Create(Shader* shader) {
	return new Material(shader);
}

void Material::Destroy(Material* mat) {
	delete mat;
}

Material::Material(Shader* shader) {
	this->shader = shader;
}

void Material::SetInt(const string& name, int value) {
	ints[name] = value;
}
void Material::SetFloat(const string& name, float value) {
	floats[name] = value;
}
void Material::SetVec2(const string& name, vec2 value) {
	vec2s[name] = value;
}
void Material::SetVec3(const string& name, vec3 value) {
	vec3s[name] = value;
}
void Material::SetVec4(const string& name, vec4 value) {
	vec4s[name] = value;
}
void Material::SetColor(const string& name, Color value) {
	colors[name] = value;
}
void Material::SetTexture(const string& name, Texture* value) {
	textures[name] = value;
}

void Material::Prepare(mat4 model, mat4 view, mat4 proj) {
	shader->Bind();

	shader->SetUniformMatrix4fv("model", model);
	shader->SetUniformMatrix4fv("view", view);
	shader->SetUniformMatrix4fv("proj", proj);

	for (auto& pair : ints)
		shader->SetUniform1i(pair.first.c_str(), pair.second);
	for (auto& pair : floats)
		shader->SetUniform1f(pair.first.c_str(), pair.second);
	for (auto& pair : vec2s)
		shader->SetUniform2f(pair.first.c_str(), pair.second);
	for (auto& pair : vec3s)
		shader->SetUniform3f(pair.first.c_str(), pair.second);
	for (auto& pair : vec4s)
		shader->SetUniform4f(pair.first.c_str(), pair.second);

	int idx = 0;
	for (auto& pair : textures) {
		pair.second->Bind(idx);
		shader->SetUniform1i(pair.first.c_str(), idx);
		++idx;
	}
}
void Material::Unbind() {
	for (auto& pair : textures)
		pair.second->Unbind();
	shader->Unbind();
}