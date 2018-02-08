#include "CameraController.h"

#include <iostream>

using namespace glm;
using namespace std;

vec2 CameraController::GetMousePosViewport() {
	return Input::GetMousePosition() / vec2(Screen::GetWidth(), Screen::GetHeight());
}

void CameraController::Deserialize(const string& serializedState) {
	Parser* parser = Parser::Create(serializedState);
	moveSpeed = parser->NextFloat();
	rotationSpeed = parser->NextVec2();
	Parser::Destroy(parser);
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

void CameraController::OnCollision(GameObject* other) {
	std::cout << "Camera collision with " << other->name << "\n";
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
	forward = normalize(forward);

	transform->LocalTranslateBy(forward * forwardSpeed * Time::DeltaTime());
	transform->LocalTranslateBy(transform->GetRight() * lateralSpeed * Time::DeltaTime());
}
