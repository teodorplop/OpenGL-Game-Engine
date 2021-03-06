#pragma once

#include "Export.h"

#include <vector>
#include "ComponentSystem.h"
#include "Transfom.h"

class GameObject {
	Transform* transform;
	std::vector<Component*> components;

	bool active;

	GameObject();
	~GameObject();

public:
	std::string name;

	OPENGL_ENGINE_API static GameObject* Create(const std::string& name);
	OPENGL_ENGINE_API static void Destroy(GameObject* obj);

	OPENGL_ENGINE_API Transform* GetTransform() const;

	OPENGL_ENGINE_API Component* AddComponent(const char* name);
	OPENGL_ENGINE_API Component* GetComponent(const char* name) const;
	OPENGL_ENGINE_API std::vector<Component*> GetComponents() const;
	OPENGL_ENGINE_API void RemoveComponent(Component* component);

	OPENGL_ENGINE_API bool IsActive() const;
	OPENGL_ENGINE_API void SetActive(bool active);
};
