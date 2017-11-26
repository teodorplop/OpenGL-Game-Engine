#pragma once

#include "Export.h"

class GameObject;
class Transform;

class Component {
	friend class ComponentSystem;

private:
	GameObject* gameObject;
	bool start;
	bool enabled;

protected:
	OPENGL_ENGINE_API virtual void Start();
	OPENGL_ENGINE_API virtual void Update();
	OPENGL_ENGINE_API virtual void OnDestroy();

public:
	OPENGL_ENGINE_API GameObject* GetGameObject() const;
	OPENGL_ENGINE_API Transform* GetTransform() const;
	OPENGL_ENGINE_API void Enable(bool enabled);
	OPENGL_ENGINE_API bool IsEnabled() const;
};