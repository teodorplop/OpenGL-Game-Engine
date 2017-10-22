#pragma once

#include "Export.h"

#include <vector>
#include "ComponentSystem.h"

class GameObject {
	std::vector<Component*> components;
public:
	OPENGL_ENGINE_API GameObject();
	OPENGL_ENGINE_API ~GameObject();
	OPENGL_ENGINE_API Component* AddComponent(const char* name);
	OPENGL_ENGINE_API Component* GetComponent(const char* name);
	OPENGL_ENGINE_API void RemoveComponent(Component* component);
};