#pragma once

#include "Export.h"

class GameObject;

class OPENGL_ENGINE_API Component {
	friend class ComponentSystem;

private:
	GameObject* gameObject;

public:
	bool enabled;

protected:
	virtual void Update();

public:
	GameObject* GetGameObject();
};