#include <OpenGL-Game-Engine.h>

#include <cstdio>

class TestComponent : public Component {
protected:
	void Update() {
		printf("TestComponent Update");
	}
};

int main() {
	ComponentSystem::Register("TestComponent", []() -> Component* { return new TestComponent(); });

	GameObject* go = new GameObject();
	go->AddComponent("TestComponent");

	Application* app = new Application("ExampleGame", 1024, 768, false);

	return 0;
}
