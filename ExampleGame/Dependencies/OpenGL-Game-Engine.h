#pragma once

#ifdef OPENGL_ENGINE_EXPORTS
#define OPENGL_ENGINE_API __declspec(dllexport)
#else
#define OPENGL_ENGINE_API __declspec(dllimport)
#endif

#include <glm.h>
#include <vector>

class Application;
class BoxCollider;
class Camera;
struct Color;
class Component;
class ComponentSystem;
class GameObject;
class Input;
class Light;
class Material;
class Mesh;
class MeshRenderer;
class Parser;
class Scene;
class Screen;
class Shader;
class Texture;
class Texture2D;
class Time;
class Transform;

class Application {
public:
	OPENGL_ENGINE_API static Application* Create(const char* windowName, int width, int height, bool fullscreen);
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
private:
	GameObject* gameObject;
	bool start;
	bool enabled;

protected:
	OPENGL_ENGINE_API virtual void Start();
	OPENGL_ENGINE_API virtual void Update();
	OPENGL_ENGINE_API virtual void OnDestroy();
	OPENGL_ENGINE_API virtual void OnCollision(GameObject* other);
	OPENGL_ENGINE_API virtual void Deserialize(const std::string& serializedState);

public:
	OPENGL_ENGINE_API GameObject* GetGameObject() const;
	OPENGL_ENGINE_API Transform* GetTransform() const;
	OPENGL_ENGINE_API void Enable(bool enabled);
	OPENGL_ENGINE_API bool IsEnabled() const;
};

class BoxCollider : public Component {};

class Camera : public Component {
protected:
	OPENGL_ENGINE_API void Deserialize(const std::string& serializedState);

public:
	OPENGL_ENGINE_API void SetClearColor(Color color);

	OPENGL_ENGINE_API float GetAspectRatio() const;
	OPENGL_ENGINE_API void SetAspectRatio(float aspect);

	OPENGL_ENGINE_API float GetNearClip() const;
	OPENGL_ENGINE_API void SetNearClip(float near);

	OPENGL_ENGINE_API float GetFarClip() const;
	OPENGL_ENGINE_API void SetFarClip(float far);

	OPENGL_ENGINE_API float GetFieldOfView() const;
	OPENGL_ENGINE_API void SetFieldOfView(float fov);
};

class ComponentSystem {
public:
	OPENGL_ENGINE_API static void Register(std::string name, Component* (create()));
};

class GameObject {
	Transform* transform;
	std::vector<Component*> components;

	bool active;

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

class Input {
public:
	OPENGL_ENGINE_API static bool GetKeyDown(int key);
	OPENGL_ENGINE_API static bool GetKey(int key);
	OPENGL_ENGINE_API static bool GetKeyUp(int key);

	OPENGL_ENGINE_API static bool GetMouseButtonDown(int button);
	OPENGL_ENGINE_API static bool GetMouseButton(int button);
	OPENGL_ENGINE_API static bool GetMouseButtonUp(int button);

	OPENGL_ENGINE_API static float GetScrollWheel();
	OPENGL_ENGINE_API static glm::vec2 GetMousePosition();
};

class Light {
public:
	OPENGL_ENGINE_API void SetDirectional(Color color);
	OPENGL_ENGINE_API Color GetColor();
};

class Material {
public:
	OPENGL_ENGINE_API static Material* Load(const std::string& name, bool clone = false);
	OPENGL_ENGINE_API static Material* Create(Shader* shader);
	OPENGL_ENGINE_API static void Destroy(Material* mat);
	OPENGL_ENGINE_API static Material* Clone(Material* original);

	OPENGL_ENGINE_API void SetInt(const std::string& name, int value);
	OPENGL_ENGINE_API void SetFloat(const std::string& name, float value);
	OPENGL_ENGINE_API void SetVec2(const std::string& name, glm::vec2 value);
	OPENGL_ENGINE_API void SetVec3(const std::string& name, glm::vec3 value);
	OPENGL_ENGINE_API void SetVec4(const std::string& name, glm::vec4 value);
	OPENGL_ENGINE_API void SetColor(const std::string& name, Color value);
	OPENGL_ENGINE_API void SetTexture(const std::string& name, Texture* texture);
};

class Mesh {
public:
	OPENGL_ENGINE_API static Mesh* Load(const std::string& filename);
	OPENGL_ENGINE_API static Mesh* Create();

	OPENGL_ENGINE_API void SetVertices(std::vector<glm::vec3> vertices);
	OPENGL_ENGINE_API void SetNormals(std::vector<glm::vec3> normals);
	OPENGL_ENGINE_API void SetColors(std::vector<Color> colors);
	OPENGL_ENGINE_API void SetUV(std::vector<glm::vec2> uvs);
	OPENGL_ENGINE_API void SetIndices(std::vector<unsigned int> indices);

	OPENGL_ENGINE_API void Clear();
};

class MeshRenderer : public Component {
protected:
	OPENGL_ENGINE_API void Deserialize(const std::string& serializedState);

public:
	OPENGL_ENGINE_API void SetMesh(Mesh* mesh);
	OPENGL_ENGINE_API void SetMaterial(Material* material);
	OPENGL_ENGINE_API Mesh* GetMesh();
	OPENGL_ENGINE_API Material* GetMaterial();
	OPENGL_ENGINE_API Material* GetSharedMaterial();
};

class Parser {
public:
	OPENGL_ENGINE_API static Parser* Create(const std::string& text);
	OPENGL_ENGINE_API static void Destroy(Parser* parser);

	OPENGL_ENGINE_API int NextInt();
	OPENGL_ENGINE_API float NextFloat();
	OPENGL_ENGINE_API glm::vec2 NextVec2();
	OPENGL_ENGINE_API glm::vec3 NextVec3();
	OPENGL_ENGINE_API glm::vec4 NextVec4();
	OPENGL_ENGINE_API Color NextColor();
	OPENGL_ENGINE_API std::string NextWord();

	OPENGL_ENGINE_API static int StringToInt(const std::string& text);
	OPENGL_ENGINE_API static float StringToFloat(const std::string& text);
	OPENGL_ENGINE_API static glm::vec2 StringToVec2(const std::string& text);
	OPENGL_ENGINE_API static glm::vec3 StringToVec3(const std::string& text);
	OPENGL_ENGINE_API static glm::vec4 StringToVec4(const std::string& text);
	OPENGL_ENGINE_API static Color StringToColor(const std::string& text);
};

class Scene {
public:
	OPENGL_ENGINE_API static void Load(const char* filename);
};

class Screen {
public:
	OPENGL_ENGINE_API static int GetWidth();
	OPENGL_ENGINE_API static int GetHeight();
	OPENGL_ENGINE_API static void SetResolution(int width, int height);
	OPENGL_ENGINE_API static void EnableCursor(bool enabled);
};

class Shader {
public:
	OPENGL_ENGINE_API static Shader* Load(const std::string& name);
	OPENGL_ENGINE_API static void Unload(Shader* shader);

	OPENGL_ENGINE_API static void SetGlobal1f(const char* name, const float& value);
	OPENGL_ENGINE_API static void SetGlobal3f(const char* name, const glm::vec3& vector);
	OPENGL_ENGINE_API static void SetGlobal4f(const char* name, const glm::vec4& vector);
};

class Texture2D {
public:
	OPENGL_ENGINE_API static Texture2D* Load(const std::string& filename);
	OPENGL_ENGINE_API static Texture2D* Create(int width, int height);
	OPENGL_ENGINE_API Color GetPixel(int x, int y);
	OPENGL_ENGINE_API void SetPixel(int x, int y, Color col);
};

class Time {
public:
	OPENGL_ENGINE_API static float RealtimeSinceStartup();
	OPENGL_ENGINE_API static float DeltaTime();
};

class Transform {
public:
	OPENGL_ENGINE_API glm::vec3 GetPosition();
	OPENGL_ENGINE_API glm::vec3 GetScale();
	OPENGL_ENGINE_API glm::vec3 GetRotation();

	OPENGL_ENGINE_API glm::vec3 GetLocalPosition();
	OPENGL_ENGINE_API glm::vec3 GetLocalRotation();
	OPENGL_ENGINE_API glm::vec3 GetLocalScale();

	OPENGL_ENGINE_API glm::vec3 GetForward();
	OPENGL_ENGINE_API glm::vec3 GetRight();
	OPENGL_ENGINE_API glm::vec3 GetUp();

	OPENGL_ENGINE_API void SetLocalPosition(glm::vec3 pos);
	OPENGL_ENGINE_API void SetLocalRotation(glm::vec3 rot);
	OPENGL_ENGINE_API void SetLocalScale(glm::vec3 scale);

	OPENGL_ENGINE_API void LocalTranslateBy(glm::vec3 distance);
	OPENGL_ENGINE_API void LocalRotateBy(glm::vec3 rot);
	OPENGL_ENGINE_API void LocalScaleBy(glm::vec3 scale);

	OPENGL_ENGINE_API Transform* GetParent();
	OPENGL_ENGINE_API void SetParent(Transform* parent);
	OPENGL_ENGINE_API std::vector<Transform*> GetChildren();
};

OPENGL_ENGINE_API std::ostream& operator<<(std::ostream& out, const Color& color);