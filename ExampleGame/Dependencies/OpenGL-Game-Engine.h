#pragma once

#ifdef OPENGL_ENGINE_EXPORTS
#define OPENGL_ENGINE_API __declspec(dllexport)
#else
#define OPENGL_ENGINE_API __declspec(dllimport)
#endif

#include <vector>

class Application {
public:
	OPENGL_ENGINE_API Application(const char* windowName, int width, int height, bool fullscreen);
};

class Component {
protected:
	virtual OPENGL_ENGINE_API void Update();
};

class ComponentSystem {
public:
	OPENGL_ENGINE_API static void Register(const char* name, Component* (create()));
};

class GameObject {
public:
	OPENGL_ENGINE_API GameObject();
	OPENGL_ENGINE_API ~GameObject();

	OPENGL_ENGINE_API Component* AddComponent(const char* name);
	OPENGL_ENGINE_API Component* GetComponent(const char* name);
	OPENGL_ENGINE_API void RemoveComponent(Component* component);

	OPENGL_ENGINE_API void SetParent(GameObject* gameObject);
	OPENGL_ENGINE_API GameObject* GetParent();
	OPENGL_ENGINE_API std::vector<GameObject*> GetChildren();
};
