#include "FunScript.h"

using namespace glm;
using namespace std;

void FunScript::Rotate() {
	vec3 rot = GetTransform()->GetLocalRotation();
	rot.y = 180 - rot.y;
	GetTransform()->SetLocalRotation(rot);
}

void FunScript::Update() {
	vec3 pos = GetTransform()->GetLocalPosition();
	GetTransform()->SetLocalPosition(pos + GetTransform()->GetForward() * moveSpeed * Time::DeltaTime());
}

void FunScript::OnCollision(GameObject* other) {
	if (other->GetComponent("FunScript") != nullptr)
		Rotate();
}

void FunScript::Deserialize(const string& serializedState) {
	Parser* parser = Parser::Create(serializedState);
	moveSpeed = parser->NextFloat();
	Parser::Destroy(parser);
}
