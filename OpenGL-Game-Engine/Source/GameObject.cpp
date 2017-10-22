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

void GameObject::AddChild(GameObject* child) {
	children.push_back(child);
}

void GameObject::RemoveChild(GameObject* child) {
	int idx = 0;
	while (idx < children.size() && children[idx] != child)
		++idx;

	if (idx < children.size())
		children.erase(children.begin() + idx);
}

void GameObject::SetParent(GameObject* parent) {
	if (this->parent != nullptr)
		this->parent->RemoveChild(this);
	this->parent = parent;
	if (this->parent != nullptr)
		this->parent->AddChild(this);
}

GameObject* GameObject::GetParent() {
	return parent;
}

std::vector<GameObject*> GameObject::GetChildren() {
	return children;
}