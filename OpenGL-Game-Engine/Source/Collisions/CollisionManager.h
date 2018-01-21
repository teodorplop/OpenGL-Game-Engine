#pragma once

#include <vector>

class BoxCollider;

class CollisionManager {
private:
	static std::vector<BoxCollider*> colliders;

	static bool CheckCollision(BoxCollider* a, BoxCollider* b);
	static void SendCollision(BoxCollider* a, BoxCollider* b);

public:
	static void Register(BoxCollider* collider);
	static void Unregister(BoxCollider* collider);
	static void Update();
};