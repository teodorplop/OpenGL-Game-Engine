#pragma once

#include <OpenGL-Game-Engine.h>
#include <glm.h>

class CameraController : public Component {
private:
	glm::vec3 initialRotation;
	glm::vec2 initialMouseViewport;

	float moveSpeed;
	glm::vec2 rotationSpeed;

	glm::vec2 GetMousePosViewport();

	void PerformMovement();
	void PerformRotation();

protected:
	void Start();
	void Update();
};