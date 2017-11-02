#pragma once

#include "Export.h"

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