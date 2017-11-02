#include "Camera.h"
#include "MeshRenderer.h"
#include "GameObject.h"
#include "Transfom.h"

#include <include\gl.h>

using namespace glm;
using namespace std;

vector<Camera*> Camera::cameras;
unordered_set<MeshRenderer*> Camera::renderers;

Camera::Camera() {
	cameras.push_back(this);
	projectionMatrix = mat4(1);
}
Camera::~Camera() {
	int idx = 0;
	while (idx < cameras.size() && cameras[idx] != this)
		++idx;

	if (idx < cameras.size())
		cameras.erase(cameras.begin() + idx);
}

void Camera::Register(MeshRenderer* renderer) {
	renderers.insert(renderer);
}
void Camera::Unregister(MeshRenderer* renderer) {
	renderers.erase(renderer);
}
void Camera::Render() {
	Color clearColor;
	glm::mat4 model, view, proj;
	Mesh* mesh;
	Material* mat;

	for (auto camera : cameras) {
		clearColor = camera->clearColor;

		view = camera->GetGameObject()->GetTransform()->GetModelMatrix();
		proj = camera->GetProjectionMatrix();

		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto renderer : renderers) {
			mesh = renderer->GetMesh();
			mat = renderer->GetMaterial();

			model = renderer->GetGameObject()->GetTransform()->GetModelMatrix();

			mat->Prepare(model, view, proj);
			mesh->Draw();
			mat->Unbind();
		}
	}
}

void Camera::SetClearColor(Color color) {
	clearColor = color;
}

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
	isDirty = true;
}
void Camera::SetNearClip(float nearClip) {
	this->nearClip = nearClip;
	isDirty = true;
}
void Camera::SetFarClip(float farClip) {
	this->farClip = farClip;
	isDirty = true;
}
void Camera::SetFieldOfView(float fov) {
	this->fieldOfView = fov;
	isDirty = true;
}

mat4 Camera::GetProjectionMatrix() {
	if (isDirty)
		projectionMatrix = glm::perspective(fieldOfView, aspectRatio, nearClip, farClip);
	return projectionMatrix;
}