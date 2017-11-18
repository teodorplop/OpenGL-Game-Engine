#include "CameraController.h"

#include <iostream>

void CameraController::Update() {
	glm::vec3 translate;
	if (Input::GetKey('W'))
		translate.z += 1.0f;
	if (Input::GetKey('S'))
		translate.z -= 1.0f;
	if (Input::GetKey('A'))
		translate.x -= 1.0f;
	if (Input::GetKey('D'))
		translate.x += 1.0f;

	GetGameObject()->GetTransform()->TranslateBy(translate * Time::DeltaTime());

	printf("before: %f\n", GetGameObject()->GetTransform()->GetRotation().y);
	GetGameObject()->GetTransform()->RotateBy(glm::vec3(0, 30, 0) * Time::DeltaTime());
	printf("after: %f\n", GetGameObject()->GetTransform()->GetRotation().y);
}