#include "Mesh.h"

using namespace std;
using namespace glm;

void Mesh::SetVertices(vector<vec3> vertices) {
	this->vertices = vertices;
	isDirty = true;
}
void Mesh::SetNormals(vector<vec3> normals) {
	this->normals = normals;
	isDirty = true;
}
void Mesh::SetUV(vector<vec2> uvs) {
	this->uvs = uvs;
	isDirty = true;
}
void Mesh::SetIndices(vector<unsigned int> indices) {
	this->indices = indices;
	isDirty = true;
}

void Mesh::Clear() {
	vertices.clear();
	normals.clear();
	uvs.clear();
	indices.clear();

	isDirty = true;
}