#pragma once

#include <include\glm.h>
#include "Export.h"
#include "Component.h"
#include "Color.h"
#include <vector>
#include <unordered_set>

class MeshRenderer;

class Camera : public Component {
private:
	static std::vector<Camera*> cameras;
	static std::unordered_set<MeshRenderer*> renderers;

	Color clearColor;
	float aspectRatio, nearClip, farClip, fieldOfView;
	glm::mat4 projectionMatrix;

	bool isDirty;

public:
	Camera();
	~Camera();

	static void Register(MeshRenderer* renderer);
	static void Unregister(MeshRenderer* renderer);
	static void Render();

	glm::mat4 GetProjectionMatrix();
	glm::mat4 GetViewMatrix();

	OPENGL_ENGINE_API void SetClearColor(Color color);

	OPENGL_ENGINE_API float GetAspectRatio() const;
	OPENGL_ENGINE_API void SetAspectRatio(float aspect);

	OPENGL_ENGINE_API float GetNearClip() const;
	OPENGL_ENGINE_API void SetNearClip(float near);

	OPENGL_ENGINE_API float GetFarClip() const;
	OPENGL_ENGINE_API void SetFarClip(float far);

	OPENGL_ENGINE_API float GetFieldOfView() const;
	OPENGL_ENGINE_API void SetFieldOfView(float fov);
};
