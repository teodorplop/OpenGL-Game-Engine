#pragma once

#include "Export.h"
#include "Component.h"
#include <include\glm.h>

class Transform : public Component {
private:
	glm::vec3 position, rotation, scale;
	glm::mat4 modelMatrix;
	
	glm::vec3 forward, right, up;

	bool isDirty;

	void RecomputeDirections();

public:
	Transform();

	OPENGL_ENGINE_API glm::vec3 GetPosition();
	OPENGL_ENGINE_API glm::vec3 GetRotation();
	OPENGL_ENGINE_API glm::vec3 GetScale();
	OPENGL_ENGINE_API glm::vec3 GetForward();
	OPENGL_ENGINE_API glm::vec3 GetRight();
	OPENGL_ENGINE_API glm::vec3 GetUp();

	OPENGL_ENGINE_API void SetPosition(glm::vec3 pos);
	OPENGL_ENGINE_API void SetRotation(glm::vec3 rot);
	OPENGL_ENGINE_API void SetScale(glm::vec3 scale);

	OPENGL_ENGINE_API void TranslateBy(glm::vec3 distance);
	OPENGL_ENGINE_API void RotateBy(glm::vec3 rot);
	OPENGL_ENGINE_API void ScaleBy(glm::vec3 scale);

	glm::mat4 GetModelMatrix();
};
