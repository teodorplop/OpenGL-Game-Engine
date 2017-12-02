#include "Camera.h"
#include "MeshRenderer.h"
#include "GameObject.h"
#include "Transfom.h"
#include "Light.h"
#include "Utils\Parser.h"

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

void Camera::Deserialize(const string& serializedState) {
	Parser* parser = Parser::Create(serializedState);

	SetAspectRatio(parser->NextFloat());
	SetNearClip(parser->NextFloat());
	SetFarClip(parser->NextFloat());
	SetFieldOfView(parser->NextFloat());
	SetClearColor(parser->NextColor());

	Parser::Destroy(parser);
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

	const vector<Light*>* const lights = Light::GetLights();
	Shader::SetGlobalLights("_Lights", *lights);
	
	for (auto camera : cameras) {
		clearColor = camera->clearColor;

		view = camera->GetViewMatrix();
		proj = camera->GetProjectionMatrix();

		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto renderer : renderers) {
			mesh = renderer->GetMesh();
			mat = renderer->GetMaterial();

			if (mesh == nullptr || mat == nullptr)
				continue;

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
	if (isDirty) {
		projectionMatrix = glm::perspective(glm::radians(fieldOfView), aspectRatio, nearClip, farClip);
		isDirty = false;
	}
	return projectionMatrix;
}

mat4 Camera::GetViewMatrix() {
	Transform* transform = GetGameObject()->GetTransform();
	return lookAt(transform->GetPosition(), transform->GetPosition() + transform->GetForward(), transform->GetUp());
}