#include "BoxCollider.h"
#include "CollisionManager.h"
#include "../GameObject.h"
#include "../Utils/Parser.h"

using namespace std;

BoxCollider::BoxCollider() {
	CollisionManager::Register(this);
}

BoxCollider::~BoxCollider() {
	CollisionManager::Unregister(this);
}

void BoxCollider::Deserialize(const string& serializedState) {
	Parser* parser = Parser::Create(serializedState);

	center = parser->NextVec3();
	size = parser->NextVec3();

	Parser::Destroy(parser);
}