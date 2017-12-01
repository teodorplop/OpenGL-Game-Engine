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

int main() {
	Application* app = Application::Create("ExampleGame", 1024, 768, false);

	RegisterGameComponents();

	Scene::Load("Test.scene");

	app->Run();

	app->Quit();

	return 0;
}
