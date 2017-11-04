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
}