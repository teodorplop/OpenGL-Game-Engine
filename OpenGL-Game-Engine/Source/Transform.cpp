#include "Transfom.h"

Transform::Transform() {
	position = glm::vec3(0, 0, 0);
	rotation = glm::quat::tquat(glm::vec3(0, 0, 0));
	scale = glm::vec3(1, 1, 1);
	modelMatrix = glm::mat4(1);
}

glm::vec3 Transform::GetPosition() {
	return position;
}
glm::vec3 Transform::GetRotation() {
	return eulerAngles(rotation);
}
glm::vec3 Transform::GetScale() {
	return scale;
}

void Transform::SetPosition(glm::vec3 pos) {
	this->position = pos;
	isDirty = true;
}
void Transform::SetRotation(glm::vec3 rot) {
	rotation = glm::quat::tquat(rot);
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
	rotation *= glm::quat::tquat(rot);
	isDirty = true;
}

glm::mat4 Transform::GetModelMatrix() {
	if (isDirty)
		modelMatrix = translate(position) * toMat4(rotation) * glm::scale(scale);

	return modelMatrix;
}