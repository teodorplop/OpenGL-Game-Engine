#pragma once

#include <include\glm.h>
#include "Export.h"
#include "Component.h"

class Camera : public Component {
private:
	float aspectRatio, nearClip, farClip, fieldOfView;
	glm::mat4 projectionMatrix;

	void UpdateProjectionMatrix();

public:
	glm::mat4 GetProjectionMatrix();

	OPENGL_ENGINE_API float GetAspectRatio() const;
	OPENGL_ENGINE_API void SetAspectRatio(float aspect);

	OPENGL_ENGINE_API float GetNearClip() const;
	OPENGL_ENGINE_API void SetNearClip(float near);

	OPENGL_ENGINE_API float GetFarClip() const;
	OPENGL_ENGINE_API void SetFarClip(float far);

	OPENGL_ENGINE_API float GetFieldOfView() const;
	OPENGL_ENGINE_API void SetFieldOfView(float fov);
};
