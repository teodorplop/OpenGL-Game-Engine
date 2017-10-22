#include "ComponentSystem.h"

void Component::Update() {}

std::unordered_set<Component*> ComponentSystem::components;
std::unordered_map<const char*, Component*(*)()> ComponentSystem::reflection;

void ComponentSystem::Register(const char* name, Component* (create())) {
	reflection.insert({ name, create });
}

Component* ComponentSystem::CreateComponent(const char* name) {
	auto it = reflection.find(name);
	if (it == reflection.end()) {
		fprintf(stderr, "Component %s not registered.", name);
		return nullptr;
	}

	Component* component = it->second();
	components.insert(component);
	return component;
}
void ComponentSystem::DestroyComponent(Component* component) {
	components.erase(component);
	delete component;
}

void ComponentSystem::Update() {
	for (auto component : components)
		component->Update();
}