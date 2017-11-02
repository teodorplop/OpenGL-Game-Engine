#include "ComponentSystem.h"
#include "GameObject.h"
#include <iostream>

std::unordered_set<Component*> ComponentSystem::components;
std::unordered_map<std::string, Component*(*)()> ComponentSystem::reflection;

void ComponentSystem::Register(std::string name, Component* (create())) {
	reflection.insert({ name, create });
}

Component* ComponentSystem::CreateComponent(std::string name, GameObject* gameObject) {
	auto it = reflection.find(name);
	if (it == reflection.end()) {
		std::cout << "Component" << name << " not registered.";
		return nullptr;
	}

	Component* component = it->second();
	component->gameObject = gameObject;
	component->enabled = true;
	components.insert(component);
	return component;
}
void ComponentSystem::DestroyComponent(Component* component) {
	components.erase(component);
	delete component;
}

void ComponentSystem::Update() {
	for (auto component : components)
		if (component->gameObject->IsActive() && component->enabled)
			component->Update();
}