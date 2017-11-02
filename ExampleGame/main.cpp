#include <OpenGL-Game-Engine.h>

#include <cstdio>
#include <iostream>

class TestComponent : public Component {
protected:
	void Update() {
		printf("TestComponent Update");
	}
};

int main() {
	Application* app = Application::Create("ExampleGame", 1024, 768, false);

	ComponentSystem::Register("TestComponent", []() -> Component* { return new TestComponent(); });

	GameObject* go = GameObject::Create();
	Component* cmp = go->AddComponent("TestComponent");

	Color col;
	Color blue = Color::blue;
	Color red = Color(1, 0, 0);

	std::cout << red << blue;

	app->Run();

	app->Quit();

	return 0;
}
