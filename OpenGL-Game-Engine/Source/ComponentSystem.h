#pragma once

#include <unordered_set>

class Component {
	friend class ComponentSystem;

protected:
	virtual void Update() {}
};

class ComponentSystem {
private:
	static std::unordered_set<Component*> components;

public:
	static void Register(Component* component);
	static void Unregister(Component* component);
	static void Update();
};

std::unordered_set<Component*> ComponentSystem::components;

void ComponentSystem::Register(Component* component) {
	components.insert(component);
}
void ComponentSystem::Unregister(Component* component) {
	components.erase(component);
	delete component;
}
void ComponentSystem::Update() {
	for (auto component : components)
		component->Update();
}