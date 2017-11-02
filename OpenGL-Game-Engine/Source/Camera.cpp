#include "Camera.h"

float Camera::GetAspectRatio() const {
	return aspectRatio;
}
float Camera::GetNearClip() const {
	return nearClip;
}
float Camera::GetFarClip() const {
	return farClip;
}
float Camera::GetFieldOfView() const {
	return fieldOfView;
}

void Camera::SetAspectRatio(float aspect) {
	this->aspectRatio = aspect;
}
void Camera::SetNearClip(float near) {
	this->nearClip = near;
}
void Camera::SetFarClip(float far) {
	this->farClip = far;
}
void Camera::SetFieldOfView(float fov) {
	this->fieldOfView = fov;
}

void Camera::UpdateProjectionMatrix() {
	projectionMatrix = glm::perspective(fieldOfView, aspectRatio, nearClip, farClip);
}