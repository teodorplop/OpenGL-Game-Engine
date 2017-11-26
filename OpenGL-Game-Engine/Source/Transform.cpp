#include "Transfom.h"

#include <iostream>

Transform* Transform::root = new Transform();

Transform::Transform() {
	if (root == nullptr) {
		localPosition = position = glm::vec3(0, 0, 0);
		localRotation = rotation = glm::vec3(0, 0, 0);
		localScale = scale = glm::vec3(1, 1, 1);

		forward = glm::vec3(0, 0, 1);
		right = glm::vec3(1, 0, 0);
		up = glm::vec3(0, 1, 0);

		modelMatrix = glm::mat4(1);
	} else
		SetParent(root);
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

glm::vec3 Transform::GetLocalPosition() {
	return localPosition;
}
glm::vec3 Transform::GetLocalRotation() {
	glm::vec3 degrees;
	degrees.x = glm::degrees(localRotation.x);
	degrees.y = glm::degrees(localRotation.y);
	degrees.z = glm::degrees(localRotation.z);
	return degrees;
}
glm::vec3 Transform::GetLocalScale() {
	return localScale;
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

void Transform::SetLocalPosition(glm::vec3 pos) {
	this->localPosition = pos;
	RecomputeModelMatrix();
}
void Transform::SetLocalRotation(glm::vec3 rot) {
	rot.x = glm::radians(rot.x);
	rot.y = glm::radians(rot.y);
	rot.z = glm::radians(rot.z);
	localRotation = rot;
	ClampRotation(localRotation);

	RecomputeModelMatrix();
	RecomputeDirections();
}
void Transform::SetLocalScale(glm::vec3 scale) {
	this->localScale = scale;
	RecomputeModelMatrix();
}

void Transform::LocalTranslateBy(glm::vec3 distance) {
	SetLocalPosition(localPosition + distance);
}
void Transform::LocalScaleBy(glm::vec3 scale) {
	SetLocalScale(this->localScale * scale);
}
void Transform::LocalRotateBy(glm::vec3 rot) {
	rot.x = glm::radians(rot.x);
	rot.y = glm::radians(rot.y);
	rot.z = glm::radians(rot.z);
	localRotation += rot;
	ClampRotation(localRotation);

	RecomputeModelMatrix();
	RecomputeDirections();
}

void Transform::RecomputeDirections() {
	forward = glm::normalize(glm::vec3(sin(rotation.y), -tan(rotation.x), cos(rotation.y)));
	right = glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0)));
	up = glm::normalize(glm::cross(right, forward));
}

void Transform::RecomputeModelMatrix() {
	position = localPosition;
	rotation = localRotation;
	scale = localScale;
	if (parent != nullptr) {
		position = parent->modelMatrix * glm::vec4(position.x, position.y, position.z, 1);
		rotation = parent->rotation + localRotation;
		ClampRotation(rotation);
		scale = parent->scale * localScale;
	}

	modelMatrix = translate(position) * glm::eulerAngleYXZ(rotation.y, rotation.x, rotation.z) * glm::scale(scale);
}

glm::mat4 Transform::GetModelMatrix() {
	return modelMatrix;
}

Transform* Transform::GetParent() {
	return parent == root ? nullptr : root;
}

void Transform::SetParent(Transform* parent) {
	if (parent == nullptr)
		parent = root;

	if (this->parent != nullptr)
		this->parent->RemoveChild(this);

	this->parent = parent;
	this->parent->AddChild(this);
	this->localPosition = glm::vec3(0, 0, 0);
	this->localRotation = glm::vec3(0, 0, 0);
	this->localScale = glm::vec3(1, 1, 1);

	RecomputeModelMatrix();
	RecomputeDirections();
}

std::vector<Transform*> Transform::GetChildren() {
	return children;
}

void Transform::AddChild(Transform* child) {
	children.push_back(child);
}

void Transform::RemoveChild(Transform* child) {
	int idx = 0;
	while (idx < children.size() && children[idx] != child)
		++idx;

	if (idx < children.size())
		children.erase(children.begin() + idx);
}

void Transform::ClampRotation(glm::vec3& rotation) {
	rotation.x = fmod(rotation.x, glm::two_pi<float>());
	rotation.y = fmod(rotation.y, glm::two_pi<float>());
	rotation.z = fmod(rotation.z, glm::two_pi<float>());
}
