#include "MeshRenderer.h"

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