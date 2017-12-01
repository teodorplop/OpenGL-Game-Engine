#pragma once

#include "Shader.h"
#include "Color.h"

#include "Export.h"

#include <include\glm.h>
#include <unordered_map>

class Texture;

class Material {
	static const std::string& path;
	static std::unordered_map<std::string, Material*> loadedMaterials;

	Shader* shader;

	std::unordered_map<std::string, int> ints;
	std::unordered_map<std::string, float> floats;
	std::unordered_map<std::string, glm::vec2> vec2s;
	std::unordered_map<std::string, glm::vec3> vec3s;
	std::unordered_map<std::string, glm::vec4> vec4s;
	std::unordered_map<std::string, Color> colors;
	std::unordered_map<std::string, Texture*> textures;

	Material(Shader* shader);
	Material(const Material& original);

public:
	OPENGL_ENGINE_API static Material* Load(const std::string& name, bool clone = false);
	OPENGL_ENGINE_API static Material* Create(Shader* shader);
	OPENGL_ENGINE_API static Material* Clone(Material* original);
	OPENGL_ENGINE_API static void Destroy(Material* mat);

	OPENGL_ENGINE_API void SetInt(const std::string& name, int value);
	OPENGL_ENGINE_API void SetFloat(const std::string& name, float value);
	OPENGL_ENGINE_API void SetVec2(const std::string& name, glm::vec2 value);
	OPENGL_ENGINE_API void SetVec3(const std::string& name, glm::vec3 value);
	OPENGL_ENGINE_API void SetVec4(const std::string& name, glm::vec4 value);
	OPENGL_ENGINE_API void SetColor(const std::string& name, Color value);
	OPENGL_ENGINE_API void SetTexture(const std::string& name, Texture* texture);

	void Prepare(glm::mat4 model, glm::mat4 view, glm::mat4 proj);
	void Unbind();
};
