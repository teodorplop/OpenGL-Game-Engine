#pragma once

#include <vector>

// Simple buffer class used to store VBOs
class Buffer {
private:
	unsigned int bufferID;
	int componentCount;

	unsigned int usage;

public:
	Buffer(bool dynamic = false);
	template <typename T> Buffer(const std::vector<T>& data, int componentCount, bool dynamic = false);
	~Buffer();

	template <typename T> void SetData(const std::vector<T>& data, int componentCount, bool dynamic = false);

	template <typename T> void UpdateData(const std::vector<T>& data);

	void Bind();
	void Unbind();

	int GetComponentCount();
};