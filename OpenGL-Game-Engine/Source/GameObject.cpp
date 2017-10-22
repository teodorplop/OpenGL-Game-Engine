#include "GameObject.h"

#include <typeinfo>
#include <iostream>

GameObject::GameObject() {
}

GameObject::~GameObject() {
	for (int i = 0; i < components.size(); ++i)
		ComponentSystem::DestroyComponent(components[i]);
	components.clear();
}

Component* GameObject::AddComponent(const char* name) {
	Component* comp = ComponentSystem::CreateComponent(name, this);
	if (comp != nullptr) {
		components.push_back(comp);
	}
	return comp;
}

Component* GameObject::GetComponent(const char* name) {
	int idx = 0;
	while (idx < components.size() && typeid(components[idx]).name() != name)
		++idx;

	return idx < components.size() ? components[idx] : nullptr;
}

void GameObject::RemoveComponent(Component* component) {
	int idx = 0;
	while (idx < components.size() && components[idx] != component)
		++idx;

	if (idx < components.size()) {
		ComponentSystem::DestroyComponent(components[idx]);
		components.erase(components.begin() + idx);
	}
}

bool GameObject::IsActive() {
	return active;
}

void GameObject::SetActive(bool active) {
	this->active = active;
}
