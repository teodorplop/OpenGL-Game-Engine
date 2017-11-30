#include <OpenGL-Game-Engine.h>

#include <cstdio>
#include <iostream>
#include <vector>

#include "Assets\Scripts\CameraController.h"

using namespace glm;
using namespace std;

void RegisterGameComponents() {
	ComponentSystem::Register("CameraController", []() -> Component* { return new CameraController(); });
}

Mesh* CreateMesh() {
	Mesh* mesh = Mesh::Create();

	vector<vec3> vertices;
	vector<vec3> normals;
	vector<Color> colors;
	vector<vec2> uvs;
	vector<unsigned int> indices;

	vertices.push_back(vec3(-0.5, -0.5, 0));
	vertices.push_back(vec3(0.5, -0.5, 0));
	vertices.push_back(vec3(0.5, 0.5, 0));
	vertices.push_back(vec3(-0.5, 0.5, 0));

	vertices.push_back(vec3(-0.5, -0.5, 1));
	vertices.push_back(vec3(0.5, -0.5, 1));
	vertices.push_back(vec3(0.5, 0.5, 1));
	vertices.push_back(vec3(-0.5, 0.5, 1));

	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));
	normals.push_back(vec3(0, 0, 0));

	colors.push_back(Color::red);
	colors.push_back(Color::red);
	colors.push_back(Color::red);
	colors.push_back(Color::red);
	colors.push_back(Color::green);
	colors.push_back(Color::green);
	colors.push_back(Color::green);
	colors.push_back(Color::green);

	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
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

	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);

	indices.push_back(4);
	indices.push_back(6);
	indices.push_back(7);

	mesh->SetVertices(vertices);
	mesh->SetColors(colors);
	mesh->SetIndices(indices);

	return mesh;
}

void CreateRandomObj() {
	Shader* shader = Shader::Create("Assets/Shaders/Default.vert", "Assets/Shaders/Default.frag");

	Material* mat = Material::Create(shader);

	Mesh* mesh = CreateMesh();

	GameObject* parent = GameObject::Create("ParentObj");
	parent->GetTransform()->SetLocalScale(vec3(0.5f, 0.5f, 1.0f));
	parent->GetTransform()->SetLocalPosition(vec3(0, 0, 0));

	GameObject* go = GameObject::Create("Mesh");
	go->GetTransform()->SetParent(parent->GetTransform());

	GameObject* cameraGO = GameObject::Create("Camera");
	Camera* camera = (Camera*)cameraGO->AddComponent("Camera");
	camera->SetClearColor(Color::gray);
	camera->SetAspectRatio(4.0f / 3.0f);
	camera->SetNearClip(0.1f);
	camera->SetFarClip(100.0f);
	camera->SetFieldOfView(30.0f);
	camera->GetTransform()->SetLocalPosition(vec3(0, 0, 5));
	camera->GetTransform()->SetLocalRotation(vec3(0, 180, 0));
	cameraGO->AddComponent("CameraController");

	MeshRenderer* mr = (MeshRenderer*)go->AddComponent("MeshRenderer");
	mr->SetMesh(mesh);
	mr->SetMaterial(mat);
}

int main() {
	Application* app = Application::Create("ExampleGame", 1024, 768, false);

	RegisterGameComponents();

	Scene::Load("Assets/Scenes/Test.scene");

	//CreateRandomObj();

	app->Run();

	app->Quit();

	return 0;
}
