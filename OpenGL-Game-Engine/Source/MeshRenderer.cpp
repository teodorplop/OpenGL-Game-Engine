#include "MeshRenderer.h"

#include "Camera.h"
#include "Utils\Parser.h"

MeshRenderer::MeshRenderer(bool rendersWater) {
	this->rendersWater = rendersWater;
	Camera::Register(this);
}

MeshRenderer::~MeshRenderer() {
	Camera::Unregister(this);
}

void MeshRenderer::SetMesh(Mesh* mesh) {
	this->mesh = mesh;
}

void MeshRenderer::SetMaterial(Material* mat) {
	this->mat = this->sharedMat = mat;
}

Mesh* MeshRenderer::GetMesh() {
	return mesh;
}

Material* MeshRenderer::GetMaterial() {
	if (mat == sharedMat)
		mat = Material::Clone(mat);
	return mat;
}

Material* MeshRenderer::GetSharedMaterial() {
	return sharedMat;
}

void MeshRenderer::Deserialize(const std::string& serializedState) {
	Parser* parser = Parser::Create(serializedState);

	std::string model = parser->NextWord();
	std::string material = parser->NextWord();

	mesh = Mesh::Load(model);
	mat = sharedMat = Material::Load(material);

	Parser::Destroy(parser);
}

bool MeshRenderer::RendersWater() {
	return rendersWater;
}