#include "CameraController.h"

#include <iostream>

using namespace glm;
using namespace std;

vec2 CameraController::GetMousePosViewport() {
	return Input::GetMousePosition() / vec2(Screen::GetWidth(), Screen::GetHeight());
}

void CameraController::Deserialize(const string& serializedState) {
	std::string::size_type sz;
	moveSpeed = std::stof(serializedState, &sz);
	vec2_fromString(serializedState.substr(sz + 1), rotationSpeed);
}

void CameraController::Start() {
	initialRotation = GetTransform()->GetRotation();
	initialMouseViewport = GetMousePosViewport();

	moveSpeed = 1.0f;
	rotationSpeed = vec2(10.0f, 10.0f);

	Screen::EnableCursor(false);
}

void CameraController::Update() {
	PerformRotation();
	PerformMovement();
}

void CameraController::PerformRotation() {
	vec2 delta = GetMousePosViewport() - initialMouseViewport;
	vec2 rot = vec2(delta.y, delta.x) * rotationSpeed;

	GetTransform()->SetLocalRotation(vec3(-rot.x, 180 - rot.y, 0));
}

void CameraController::PerformMovement() {
	float forwardSpeed = 0.0f;
	if (Input::GetKey('W'))
		forwardSpeed = moveSpeed;
	else if (Input::GetKey('S'))
		forwardSpeed = -moveSpeed;

	float lateralSpeed = 0.0f;
	if (Input::GetKey('D'))
		lateralSpeed = moveSpeed;
	else if (Input::GetKey('A'))
		lateralSpeed = -moveSpeed;

	Transform* transform = GetTransform();
	vec3 forward = transform->GetForward();
	forward.y = 0;

	transform->LocalTranslateBy(forward * forwardSpeed * Time::DeltaTime());
	transform->LocalTranslateBy(transform->GetRight() * lateralSpeed * Time::DeltaTime());
}
