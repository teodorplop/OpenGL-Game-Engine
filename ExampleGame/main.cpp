#include "Application.h"
#include "Component.h"
#include "ComponentSystem.h"
#include "Scene.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "Code/CameraController.h"
#include "Code/FunScript.h"

using namespace glm;
using namespace std;

void RegisterGameComponents() {
	ComponentSystem::Register("CameraController", []() -> Component* { return new CameraController(); });
	ComponentSystem::Register("FunScript", []() -> Component* { return new FunScript(); });
}

int main() {
	Application* app = Application::Create("ExampleGame", 1024, 768, false);

	RegisterGameComponents();

	Scene::Load("Test.scene");

	app->Run();

	app->Quit();

	return 0;
}
