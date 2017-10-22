#pragma once

#ifdef OPENGL_ENGINE_EXPORTS
#define OPENGL_ENGINE_API __declspec(dllexport)
#else
#define OPENGL_ENGINE_API __declspec(dllimport)
#endif

class Application {
public:
	OPENGL_ENGINE_API Application(const char* windowName, int width, int height);
};

class Component {
protected:
	virtual OPENGL_ENGINE_API void Update() {}
};

class GameObject {
public:
	template <class T> OPENGL_ENGINE_API T* AddComponent();
	template <class T> OPENGL_ENGINE_API T* AddMissingComponent();
	template <class T> OPENGL_ENGINE_API T* GetComponent();
	OPENGL_ENGINE_API void RemoveComponent(Component* component);
};