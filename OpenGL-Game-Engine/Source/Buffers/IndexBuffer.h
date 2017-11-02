#pragma once

#include <vector>

// Simple buffer class used to store IBOs
class IndexBuffer {
private:
	unsigned int bufferID;
	int count;

	unsigned int usage;
public:
	IndexBuffer(bool dynamic = false);
	IndexBuffer(const std::vector<unsigned int>& data, bool dynamic = false);
	~IndexBuffer();

	void SetData(const std::vector<unsigned int>& data, bool dynamic = false);
	void UpdateData(const std::vector<unsigned int>& data);

	void Bind();
	void Unbind();

	int GetCount();
};