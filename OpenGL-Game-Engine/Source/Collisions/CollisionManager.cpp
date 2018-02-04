#include "CollisionManager.h"
#include "BoxCollider.h"
#include "../Transfom.h"
#include "../GameObject.h"

using namespace std;
using namespace glm;

vector<BoxCollider*> CollisionManager::colliders;

void CollisionManager::Register(BoxCollider* collider) {
	colliders.push_back(collider);
}

void CollisionManager::Unregister(BoxCollider* collider) {
	unsigned int idx = 0;
	while (idx < colliders.size() && colliders[idx] != collider)
		++idx;
	if (idx < colliders.size())
		colliders.erase(colliders.begin() + idx);
}

void CollisionManager::Update() {
	for (unsigned int i = 0; i < colliders.size(); ++i)
		for (unsigned int j = i + 1; j < colliders.size(); ++j)
			if (CheckCollision(colliders[i], colliders[j]))
				SendCollision(colliders[i], colliders[j]);
}

bool CollisionManager::CheckCollision(BoxCollider* a, BoxCollider* b) {
	vec3 aCenter = a->GetTransform()->GetPosition() + a->center;
	vec3 bCenter = b->GetTransform()->GetPosition() + b->center;

	vec3 aSize = a->GetTransform()->GetScale() * a->size;
	vec3 bSize = b->GetTransform()->GetScale() * b->size;

	if (abs(aCenter.x - bCenter.x) < aSize.x / 2 + bSize.x / 2 &&
		abs(aCenter.y - bCenter.y) < aSize.y / 2 + bSize.y / 2 &&
		abs(aCenter.z - bCenter.z) < aSize.z / 2 + bSize.z / 2)
		return true;
	return false;
}

void CollisionManager::SendCollision(BoxCollider* a, BoxCollider* b) {
	vector<Component*> comps = a->GetGameObject()->GetComponents();
	GameObject* go = b->GetGameObject();
	for (auto comp : comps)
		comp->OnCollision(go);

	comps = b->GetGameObject()->GetComponents();
	go = a->GetGameObject();
	for (auto comp : comps)
		comp->OnCollision(go);
}