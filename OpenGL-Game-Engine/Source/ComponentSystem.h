#pragma once

#include "Export.h"

#include <unordered_set>
#include <unordered_map>

class GameObject;

class Component {
	friend class ComponentSystem;

private:
	GameObject* gameObject;

public:
	bool enabled;

protected:
	OPENGL_ENGINE_API virtual void Update();

public:
	GameObject* GetGameObject();
};

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
