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
	colors.push_back(Color::green);
	colors.push_back(Color::blue);
	colors.push_back(Color::yellow);
	colors.push_back(Color::red);
	colors.push_back(Color::green);
	colors.push_back(Color::blue);
	colors.push_back(Color::yellow);

	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 0));

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(1);

	indices.push_back(0);
	indices.push_back(3);
	indices.push_back(2);

	indices.push_back(4);
	indices.push_back(6);
	indices.push_back(5);

	indices.push_back(4);
	indices.push_back(7);
	indices.push_back(6);

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
	//go->GetTransform()->SetPosition(vec3(0, 0, 0));

	GameObject* cameraGO = GameObject::Create();
	Camera* camera = (Camera*)cameraGO->AddComponent("Camera");
	camera->SetClearColor(Color::gray);
	camera->SetAspectRatio(4 / 3);
	camera->SetNearClip(0.1f);
	camera->SetFarClip(100);
	camera->SetFieldOfView(50);
	camera->GetGameObject()->GetTransform()->SetLocalPosition(vec3(0, 0, -5));
	cameraGO->AddComponent("CameraController");

	MeshRenderer* mr = (MeshRenderer*)go->AddComponent("MeshRenderer");
	mr->SetMesh(mesh);
	mr->SetMaterial(mat);
}

int main() {
	/*vec3 position = vec3(0, 0, 0);
	vec3 rotation = vec3(radians(90.0f), radians(90.0f), radians(0.0f));
	vec3 scale = vec3(1, 1, 1);

	mat4 rotationMatrix = glm::eulerAngleYXZ(rotation.y, rotation.x, rotation.z);
	mat4 parentMatrix = glm::translate(position) * rotationMatrix * glm::scale(scale);

	vec3 pos = parentMatrix * vec4(0, 1, 1, 1);
	std::cout << pos << "\n\n\n";

	quat rotationQ = quat::tquat(rotation);
	vec3 qAngles = eulerAngles(rotationQ);
	qAngles.x = degrees(qAngles.x);
	qAngles.y = degrees(qAngles.y);
	qAngles.z = degrees(qAngles.z);
	std::cout << qAngles << "\n\n\n";*/

	Application* app = Application::Create("ExampleGame", 1024, 768, false);

	RegisterGameComponents();

	CreateRandomObj();

	app->Run();

	app->Quit();

	return 0;
}
