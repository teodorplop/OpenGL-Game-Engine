#pragma once

#include <include\glm.h>

class UICamera {
private:
	float aspectRatio;
	glm::mat4 viewMatrix, projectionMatrix;

	bool isDirty;

public:
	UICamera();
	~UICamera();


};
