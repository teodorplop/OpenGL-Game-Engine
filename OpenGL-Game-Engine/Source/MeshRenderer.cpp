#include "MeshRenderer.h"

#include "Camera.h"

MeshRenderer::MeshRenderer() {
	Camera::Register(this);
}

MeshRenderer::~MeshRenderer() {
	Camera::Unregister(this);
}

void MeshRenderer::SetMesh(Mesh* mesh) {
	this->mesh = mesh;
}

void MeshRenderer::SetMaterial(Material* mat) {
	this->mat = mat;
}

Mesh* MeshRenderer::GetMesh() {
	return mesh;
}

Material* MeshRenderer::GetMaterial() {
	return mat;
}