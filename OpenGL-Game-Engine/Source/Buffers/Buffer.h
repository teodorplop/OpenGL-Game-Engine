#pragma once

#include <vector>
#include <include\glm.h>
#include "../Color.h"

// Simple buffer class used to store VBOs
class Buffer {
private:
	unsigned int bufferID;
	int componentCount;

	unsigned int usage;

public:
	Buffer(int componentCount, bool dynamic = false);
	Buffer(const std::vector<float>& data, bool dynamic = false);
	Buffer(const std::vector<glm::vec2>& data, bool dynamic = false);
	Buffer(const std::vector<glm::vec3>& data, bool dynamic = false);
	Buffer(const std::vector<glm::vec4>& data, bool dynamic = false);
	Buffer(const std::vector<Color>& data, bool dynamic = false);
	~Buffer();

	void SetData(const std::vector<float>& data, bool dynamic = false);
	void SetData(const std::vector<glm::vec2>& data, bool dynamic = false);
	void SetData(const std::vector<glm::vec3>& data, bool dynamic = false);
	void SetData(const std::vector<glm::vec4>& data, bool dynamic = false);
	void SetData(const std::vector<Color>& data, bool dynamic = false);

	void UpdateData(const std::vector<float>& data);
	void UpdateData(const std::vector<glm::vec2>& data);
	void UpdateData(const std::vector<glm::vec3>& data);
	void UpdateData(const std::vector<glm::vec4>& data);
	void UpdateData(const std::vector<Color>& data);

	void Bind();
	void Unbind();

	int GetComponentCount();
};