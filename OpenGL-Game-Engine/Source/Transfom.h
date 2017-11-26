#pragma once

#include "Export.h"
#include "Component.h"
#include <include\glm.h>
#include <vector>

class Transform {
private:
	glm::vec3 localPosition, localRotation, localScale;
	glm::vec3 position, rotation, scale;
	glm::mat4 modelMatrix;
	
	glm::vec3 forward, right, up;

	Transform *parent;
	std::vector<Transform*> children;

	void AddChild(Transform* child);
	void RemoveChild(Transform* child);

	void RecomputeDirections();
	void RecomputeModelMatrix();

	static Transform* root;
	static void ClampRotation(glm::vec3& rotation);

public:
	Transform();

	OPENGL_ENGINE_API glm::vec3 GetPosition();
	OPENGL_ENGINE_API glm::vec3 GetScale();
	OPENGL_ENGINE_API glm::vec3 GetRotation();

	OPENGL_ENGINE_API glm::vec3 GetLocalPosition();
	OPENGL_ENGINE_API glm::vec3 GetLocalRotation();
	OPENGL_ENGINE_API glm::vec3 GetLocalScale();

	OPENGL_ENGINE_API glm::vec3 GetForward();
	OPENGL_ENGINE_API glm::vec3 GetRight();
	OPENGL_ENGINE_API glm::vec3 GetUp();

	OPENGL_ENGINE_API void SetLocalPosition(glm::vec3 pos);
	OPENGL_ENGINE_API void SetLocalRotation(glm::vec3 rot);
	OPENGL_ENGINE_API void SetLocalScale(glm::vec3 scale);

	OPENGL_ENGINE_API void LocalTranslateBy(glm::vec3 distance);
	OPENGL_ENGINE_API void LocalRotateBy(glm::vec3 rot);
	OPENGL_ENGINE_API void LocalScaleBy(glm::vec3 scale);

	OPENGL_ENGINE_API Transform* GetParent();
	OPENGL_ENGINE_API void SetParent(Transform* parent);
	OPENGL_ENGINE_API std::vector<Transform*> GetChildren();

	glm::mat4 GetModelMatrix();
};
