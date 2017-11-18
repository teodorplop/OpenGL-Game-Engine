#include "Transfom.h"

Transform::Transform() {
	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);

	forward = glm::vec3(0, 0, 1);
	right = glm::vec3(1, 0, 0);
	up = glm::vec3(0, 1, 0);

	modelMatrix = glm::mat4(1);
}

glm::vec3 Transform::GetPosition() {
	return position;
}
glm::vec3 Transform::GetRotation() {
	glm::vec3 degrees;
	degrees.x = glm::degrees(rotation.x);
	degrees.y = glm::degrees(rotation.y);
	degrees.z = glm::degrees(rotation.z);
	return degrees;
}
glm::vec3 Transform::GetScale() {
	return scale;
}
glm::vec3 Transform::GetForward() {
	return forward;
}
glm::vec3 Transform::GetRight() {
	return right;
}
glm::vec3 Transform::GetUp() {
	return up;
}

void Transform::SetPosition(glm::vec3 pos) {
	this->position = pos;
	isDirty = true;
}
void Transform::SetRotation(glm::vec3 rot) {
	rot.x = glm::radians(rot.x);
	rot.y = glm::radians(rot.y);
	rot.z = glm::radians(rot.z);

	rotation = rot;
	rotation.x = fmod(rotation.x, glm::two_pi<float>());
	rotation.y = fmod(rotation.y, glm::two_pi<float>());
	rotation.z = fmod(rotation.z, glm::two_pi<float>());

	RecomputeDirections();
	isDirty = true;
}
void Transform::SetScale(glm::vec3 scale) {
	this->scale = scale;
	isDirty = true;
}

void Transform::TranslateBy(glm::vec3 distance) {
	SetPosition(position + distance);
}

void Transform::ScaleBy(glm::vec3 scale) {
	SetScale(this->scale * scale);
}

void Transform::RotateBy(glm::vec3 rot) {
	rot.x = glm::radians(rot.x);
	rot.y = glm::radians(rot.y);
	rot.z = glm::radians(rot.z);

	SetRotation(rotation + rot);
}

void Transform::RecomputeDirections() {
	forward = glm::normalize(glm::vec3(sin(rotation.y), -tan(rotation.x), cos(rotation.y)));
	right = glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0)));
	up = glm::normalize(glm::cross(right, forward));
}

glm::mat4 Transform::GetModelMatrix() {
	if (isDirty) {
		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1), rotation.x, glm::vec3(1, 0, 0));
		rotationMatrix = glm::rotate(rotationMatrix, rotation.y, glm::vec3(0, 1, 0));
		rotationMatrix = glm::rotate(rotationMatrix, rotation.z, glm::vec3(0, 0, 1));
		modelMatrix = translate(position) * rotationMatrix * glm::scale(scale);
		isDirty = false;
	}

	return modelMatrix;
}
