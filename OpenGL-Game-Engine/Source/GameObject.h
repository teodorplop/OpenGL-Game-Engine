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
	GameObject();
	~GameObject();

	OPENGL_ENGINE_API static GameObject* Create();
	OPENGL_ENGINE_API static void Destroy(GameObject* obj);

	OPENGL_ENGINE_API Component* AddComponent(const char* name);
	OPENGL_ENGINE_API Component* GetComponent(const char* name) const;
	OPENGL_ENGINE_API void RemoveComponent(Component* component);

	OPENGL_ENGINE_API bool IsActive() const;
	OPENGL_ENGINE_API void SetActive(bool active);

	OPENGL_ENGINE_API void SetParent(GameObject* gameObject);
	OPENGL_ENGINE_API GameObject* GetParent() const;
	OPENGL_ENGINE_API std::vector<GameObject*> GetChildren() const;
};
