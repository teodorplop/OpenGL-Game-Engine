#pragma once

#include "Component.h"

#include <unordered_set>
#include <unordered_map>

class ComponentSystem {
private:
	static std::unordered_set<Component*> components;
	static std::unordered_map<const char*, Component*(*)()> reflection;

public:
	OPENGL_ENGINE_API static void Register(const char* name, Component* (create()));

	static Component* CreateComponent(const char* name, GameObject* gameObject);
	static void DestroyComponent(Component* component);
	static void Update();
};
