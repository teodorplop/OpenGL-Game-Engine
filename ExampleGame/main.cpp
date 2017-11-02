#include <OpenGL-Game-Engine.h>

#include <cstdio>
#include <iostream>
#include <vector>

using namespace glm;
using namespace std;

class TestComponent : public Component {
protected:
	void Update() {
		printf("TestComponent Update");
	}
};

void RegisterGameComponents() {
	ComponentSystem::Register("TestComponent", []() -> Component* { return new TestComponent(); });
}

Mesh* CreateMesh() {
	Mesh* mesh = Mesh::Create();

	vector<vec3> vertices;
	vector<vec3> normals;
	vector<Color> colors;
	vector<vec2> uvs;
	vector<unsigned int> indices;

	vertices.push_back(vec3(-0.6, -0.5, 0));
	vertices.push_back(vec3(0.5, -0.5, 0));
	vertices.push_back(vec3(0.5, 0.5, 0));
	vertices.push_back(vec3(-0.5, 0.5, 0));

	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));

	colors.push_back(Color::white);
	colors.push_back(Color::white);
	colors.push_back(Color::white);
	colors.push_back(Color::white);

	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);

	mesh->SetVertices(vertices);
	mesh->SetColors(colors);
	mesh->SetIndices(indices);

	return mesh;
}

void CreateRandomObj() {
	Shader* shader = Shader::Create("Assets/Shaders/Default.vert", "Assets/Shaders/Default.frag");

	Material* mat = Material::Create(shader);

	Mesh* mesh = CreateMesh();

	GameObject* go = GameObject::Create();

	GameObject* cameraGO = GameObject::Create();
	Camera* camera = (Camera*)cameraGO->AddComponent("Camera");
	camera->SetClearColor(Color::gray);

	MeshRenderer* mr = (MeshRenderer*)go->AddComponent("MeshRenderer");
	mr->SetMesh(mesh);
	mr->SetMaterial(mat);
}

int main() {
	Application* app = Application::Create("ExampleGame", 1024, 768, false);

	RegisterGameComponents();

	CreateRandomObj();

	app->Run();

	app->Quit();

	return 0;
}
