#include "CameraController.h"

#include <iostream>

void CameraController::Update() {
	glm::vec3 translate;
	if (Input::GetKey('W'))
		translate.y += 1.0f;
	if (Input::GetKey('S'))
		translate.y -= 1.0f;
	if (Input::GetKey('A'))
		translate.x -= 1.0f;
	if (Input::GetKey('D'))
		translate.x += 1.0f;

	GetGameObject()->GetTransform()->LocalTranslateBy(translate * Time::DeltaTime());
	//printf("before: %f\n", GetGameObject()->GetTransform()->GetRotation().y);
	//GetGameObject()->GetTransform()->LocalRotateBy(glm::vec3(0, 60, 0) * Time::DeltaTime());
	//printf("after: %f\n", GetGameObject()->GetTransform()->GetRotation().y);
}
