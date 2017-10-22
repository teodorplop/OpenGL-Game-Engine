#pragma once

#include "Export.h"

#include <vector>
#include "ComponentSystem.h"

class GameObject {
	std::vector<Component*> components;
public:
	template <class T> OPENGL_ENGINE_API T* AddComponent();
	template <class T> OPENGL_ENGINE_API T* AddMissingComponent();
	template <class T> OPENGL_ENGINE_API T* GetComponent();
	OPENGL_ENGINE_API void RemoveComponent(Component* component);
};

template <class T> T* GameObject::AddComponent() {
	static_assert(std::is_base_of<Component, T>::value, "Type parameter of this class must derive from Component");

	T* t = new T();
	ComponentSystem::Register(t);
	components.push_back(t);
	return t;
}

template <class T> T* GameObject::AddMissingComponent() {
	static_assert(std::is_base_of<Component, T>::value, "Type parameter of this class must derive from Component");

	T* t = GetComponent<T>();
	if (t == nullptr)
		t = AddComponent<T>();
	return t;
}

template <class T> T* GameObject::GetComponent() {
	static_assert(std::is_base_of<Component, T>::value, "Type parameter of this class must derive from Component");

	T* t = nullptr;
	for (int i = 0; t == nullptr && i < components.size(); ++i)
		t = dynamic_cast<T*>(components[i]);
	return t;
}

void GameObject::RemoveComponent(Component* component) {
	int idx = 0;
	while (idx < components.size() && components[idx] != component)
		++idx;

	if (idx < components.size()) {
		ComponentSystem::Unregister(components[idx]);
		components.erase(components.begin() + idx);
	}
}