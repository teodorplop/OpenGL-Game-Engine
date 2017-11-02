#pragma once

#ifdef OPENGL_ENGINE_EXPORTS
#define OPENGL_ENGINE_API __declspec(dllexport)
#else
#define OPENGL_ENGINE_API __declspec(dllimport)
#endif

#include <vector>

class Application;
struct Color;
class Component;
class ComponentSystem;
class GameObject;
class Input;
class Material;
class Mesh;
class MeshRenderer;
class Shader;
class Texture;
class Texture2D;
class Time;

class Application {
public:
	OPENGL_ENGINE_API Application(const char* windowName, int width, int height, bool fullscreen);
	OPENGL_ENGINE_API void Run();
	OPENGL_ENGINE_API void Quit();
};

struct Color {
	OPENGL_ENGINE_API static Color black, gray, white, red, green, blue, yellow;

	float r, g, b, a;

	OPENGL_ENGINE_API Color();
	OPENGL_ENGINE_API Color(float r, float g, float b, float a = 1);
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

class Input {
public:
	OPENGL_ENGINE_API static bool GetKeyDown(int key);
	OPENGL_ENGINE_API static bool GetKey(int key);
	OPENGL_ENGINE_API static bool GetKeyUp(int key);

	OPENGL_ENGINE_API static bool GetMouseButtonDown(int button);
	OPENGL_ENGINE_API static bool GetMouseButton(int button);
	OPENGL_ENGINE_API static bool GetMouseButtonUp(int button);

	OPENGL_ENGINE_API static float GetScrollWheel();
	//OPENGL_ENGINE_API static glm::vec2 GetMousePosition();
};

class Material {
public:
	OPENGL_ENGINE_API Material(Shader* shader);

	OPENGL_ENGINE_API void SetInt(const std::string& name, int value);
	OPENGL_ENGINE_API void SetFloat(const std::string& name, float value);
	//OPENGL_ENGINE_API void SetVec2(const std::string& name, glm::vec2 value);
	//OPENGL_ENGINE_API void SetVec3(const std::string& name, glm::vec3 value);
	//OPENGL_ENGINE_API void SetVec4(const std::string& name, glm::vec4 value);
	OPENGL_ENGINE_API void SetColor(const std::string& name, Color value);
	OPENGL_ENGINE_API void SetTexture(const std::string& name, Texture* texture);
};

class Mesh {
public:
	//OPENGL_ENGINE_API void SetVertices(std::vector<glm::vec3> vertices);
	//OPENGL_ENGINE_API void SetNormals(std::vector<glm::vec3> normals);
	//OPENGL_ENGINE_API void SetUV(std::vector<glm::vec2> uvs);
	OPENGL_ENGINE_API void SetIndices(std::vector<unsigned int> indices);

	OPENGL_ENGINE_API void Clear();
};

class MeshRenderer {
public:
	OPENGL_ENGINE_API void SetMesh(Mesh* mesh);
	OPENGL_ENGINE_API void SetMaterial(Material* material);
	OPENGL_ENGINE_API Mesh* GetMesh();
	OPENGL_ENGINE_API Material* GetMaterial();
};

class Texture2D {
public:
	OPENGL_ENGINE_API static Texture2D* Create(const char* filename);
	OPENGL_ENGINE_API static Texture2D* Create(int width, int height);
	OPENGL_ENGINE_API Color GetPixel(int x, int y);
	OPENGL_ENGINE_API void SetPixel(int x, int y, Color col);
};

class Time {
public:
	OPENGL_ENGINE_API static float RealtimeSinceStartup();
	OPENGL_ENGINE_API static float DeltaTime();
};