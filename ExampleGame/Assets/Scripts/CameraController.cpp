#include "CameraController.h"

#include <iostream>

using namespace glm;

void CameraController::Update() {
	vec3 translate;
	if (Input::GetKey('W'))
		translate.y += 1.0f;
	if (Input::GetKey('S'))
		translate.y -= 1.0f;
	if (Input::GetKey('A'))
		translate.x -= 1.0f;
	if (Input::GetKey('D'))
		translate.x += 1.0f;

	GetGameObject()->GetTransform()->LocalTranslateBy(translate * Time::DeltaTime());

	std::cout << Input::GetMousePosition() << "\n";
	//printf("before: %f\n", GetGameObject()->GetTransform()->GetRotation().y);
	//GetGameObject()->GetTransform()->LocalRotateBy(glm::vec3(0, 60, 0) * Time::DeltaTime());
	//printf("after: %f\n", GetGameObject()->GetTransform()->GetRotation().y);
}
