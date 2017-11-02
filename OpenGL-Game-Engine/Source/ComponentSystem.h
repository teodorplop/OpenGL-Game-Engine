#pragma once

#include "Component.h"

#include <unordered_set>
#include <unordered_map>
#include <string>

class ComponentSystem {
private:
	static std::unordered_set<Component*> components;
	static std::unordered_map<std::string, Component*(*)()> reflection;

public:
	OPENGL_ENGINE_API static void Register(std::string name, Component* (create()));

	static Component* CreateComponent(std::string name, GameObject* gameObject);
	static void DestroyComponent(Component* component);
	static void Update();
};
