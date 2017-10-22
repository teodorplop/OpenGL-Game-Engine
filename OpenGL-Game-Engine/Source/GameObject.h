#pragma once

#include "Export.h"

#include <vector>
#include "ComponentSystem.h"

class GameObject {
	std::vector<Component*> components;

	bool active;

	GameObject* parent;
	std::vector<GameObject*> children;

	void RemoveChild(GameObject* child);
	void AddChild(GameObject* child);

public:
	OPENGL_ENGINE_API GameObject();
	OPENGL_ENGINE_API ~GameObject();

	OPENGL_ENGINE_API Component* AddComponent(const char* name);
	OPENGL_ENGINE_API Component* GetComponent(const char* name);
	OPENGL_ENGINE_API void RemoveComponent(Component* component);

	OPENGL_ENGINE_API bool IsActive();
	OPENGL_ENGINE_API void SetActive(bool active);

	OPENGL_ENGINE_API void SetParent(GameObject* gameObject);
	OPENGL_ENGINE_API GameObject* GetParent();
	OPENGL_ENGINE_API std::vector<GameObject*> GetChildren();
};
