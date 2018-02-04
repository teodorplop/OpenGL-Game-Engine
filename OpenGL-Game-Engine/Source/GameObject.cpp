#include "GameObject.h"

#include <typeinfo>
#include <iostream>

using namespace std;

GameObject* GameObject::Create(const std::string& name) {
	GameObject* go = new GameObject();
	go->name = name;
	return go;
}

void GameObject::Destroy(GameObject* obj) {
	delete obj;
}

GameObject::GameObject() {
	active = true;
	transform = new Transform();
}

GameObject::~GameObject() {
	delete transform;
	for (int i = 0; i < components.size(); ++i)
		ComponentSystem::DestroyComponent(components[i]);
	components.clear();
}

Transform* GameObject::GetTransform() const {
	return transform;
}

Component* GameObject::AddComponent(const char* name) {
	Component* comp = ComponentSystem::CreateComponent(name, this);
	if (comp != nullptr) {
		components.push_back(comp);
	}
	return comp;
}

Component* GameObject::GetComponent(const char* name) const {
	int idx = 0;
	while (idx < components.size() && strcmp(typeid(*components[idx]).name() + 6, name) != 0)
		++idx;

	return idx < components.size() ? components[idx] : nullptr;
}

vector<Component*> GameObject::GetComponents() const {
	return components;
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

bool GameObject::IsActive() const {
	return active;
}

void GameObject::SetActive(bool active) {
	this->active = active;
}