#include "Mesh.h"

#include "Utils\ObjLoader.h"

using namespace std;
using namespace glm;

const string& Mesh::path = "Assets/Models/";

Mesh* Mesh::Load(const std::string& filename) {
	string fullPath = path + filename;
	const char* fullPathCStr = fullPath.c_str();

	vector<vec3> vertices;
	vector<vec2> uvs;
	vector<vec3> normals;
	vector<unsigned int> indices;

	Mesh* mesh = new Mesh();
	if (ObjLoader::LoadObj(fullPathCStr, vertices, uvs, normals, indices)) {
		mesh->SetVertices(vertices);
		mesh->SetUV(uvs);
		mesh->SetNormals(normals);
		mesh->SetIndices(indices);
	}

	return mesh;
}

Mesh* Mesh::Create() {
	return new Mesh();
}

Mesh::Mesh() {
	GenerateGLMesh();
}

void Mesh::GenerateGLMesh() {
	vertexBuffer = new Buffer(vector<vec3>(1));
	normalBuffer = new Buffer(vector<vec3>(1));
	colorBuffer = new Buffer(vector<Color>(1));
	uvBuffer = new Buffer(vector<vec2>(1));

	vao = new VertexArray();
	vao->AddBuffer(vertexBuffer, 0);
	vao->AddBuffer(normalBuffer, 1);
	vao->AddBuffer(colorBuffer, 2);
	vao->AddBuffer(uvBuffer, 3);

	indexBuffer = new IndexBuffer(vector<unsigned int>(1));
}

void Mesh::SetVertices(vector<vec3> vertices) {
	this->vertices = vertices;
	vertexBuffer->SetData(vertices);
}
void Mesh::SetNormals(vector<vec3> normals) {
	this->normals = normals;
	normalBuffer->SetData(normals);
}
void Mesh::SetColors(vector<Color> colors) {
	this->colors = colors;
	colorBuffer->SetData(colors);
}
void Mesh::SetUV(vector<vec2> uvs) {
	this->uvs = uvs;
	uvBuffer->SetData(uvs);
}
void Mesh::SetIndices(vector<unsigned int> indices) {
	this->indices = indices;
	indexBuffer->SetData(indices);
}

void Mesh::Clear() {
	vertices.clear();
	normals.clear();
	uvs.clear();
	indices.clear();

	vertexBuffer->SetData(vertices);
	normalBuffer->SetData(normals);
	uvBuffer->SetData(uvs);
	indexBuffer->SetData(indices);
}

void Mesh::Draw() {
	Bind();
	glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);
	Unbind();
}

void Mesh::Bind() {
	vao->Bind();
	indexBuffer->Bind();
}

void Mesh::Unbind() {
	indexBuffer->Unbind();
	vao->Unbind();
}