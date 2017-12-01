#include "Material.h"

#include "Utils\XML\pugixml.hpp"
#include "Utils\Parser.h"
#include "Texture2D.h"

using namespace std;
using namespace glm;

const string& Material::path = "Assets/Materials/";
unordered_map<string, Material*> Material::loadedMaterials;

Material* Material::Load(const string& name, bool clone) {
	auto it = loadedMaterials.find(name);
	if (it == loadedMaterials.end() || clone) {
		string completePath = path + name;
		const char* filename = completePath.c_str();

		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file(filename);

		if (!result) {
			cout << filename << " Material XML Error: " << result.description() << ' ' << "XML Error Offset: " << result.offset;
			return nullptr;
		}

		auto shaderChild = doc.child("Shader");
		Shader* shader = Shader::Load(shaderChild.attribute("name").value());
		Material* mat = Create(shader);

		auto children = shaderChild.children();
		for (auto& child : children) {
			string type = child.attribute("type").value();

			if (type == "int")
				mat->SetInt(child.name(), child.attribute("value").as_int());
			else if (type == "float")
				mat->SetFloat(child.name(), child.attribute("value").as_float());
			else if (type == "vec2")
				mat->SetVec2(child.name(), Parser::StringToVec2(child.attribute("value").value()));
			else if (type == "vec3")
				mat->SetVec3(child.name(), Parser::StringToVec3(child.attribute("value").value()));
			else if (type == "vec4")
				mat->SetVec4(child.name(), Parser::StringToVec4(child.attribute("value").value()));
			else if (type == "Color")
				mat->SetColor(child.name(), Parser::StringToColor(child.attribute("value").value()));
			else if (type == "Texture2D")
				mat->SetTexture(child.name(), Texture2D::Load(child.attribute("value").value()));
		}

		if (it == loadedMaterials.end())
			loadedMaterials.insert({ name, mat });

		return mat;
	}
	return it->second;
}

Material* Material::Create(Shader* shader) {
	return new Material(shader);
}

Material* Material::Clone(Material* mat) {
	Material* clone = Material::Create(mat->shader);
	*clone = *mat;
	return clone;
}

void Material::Destroy(Material* mat) {
	delete mat;
}

Material::Material(Shader* shader) {
	this->shader = shader;
}

Material::Material(const Material& original) {
	ints = original.ints;
	floats = original.floats;
	vec2s = original.vec2s;
	vec3s = original.vec3s;
	vec4s = original.vec4s;
	colors = original.colors;
	textures = original.textures;
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
		const char* textureName = pair.first.c_str();
		shader->SetUniform1i(textureName, idx);
		pair.second->Bind(idx);
		++idx;
	}
}
void Material::Unbind() {
	for (auto& pair : textures)
		pair.second->Unbind();
	shader->Unbind();
}