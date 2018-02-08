#include "FunScript.h"

using namespace glm;
using namespace std;

void FunScript::Update() {
	GetTransform()->LocalTranslateBy(GetTransform()->GetForward() * moveSpeed * Time::DeltaTime());
}

void FunScript::OnCollision(GameObject* other) {
	if (other->GetComponent("FunScript") != nullptr)
		GetTransform()->LocalRotateBy(vec3(0, 180, 0));
}

void FunScript::Deserialize(const string& serializedState) {
	Parser* parser = Parser::Create(serializedState);
	moveSpeed = parser->NextFloat();
	Parser::Destroy(parser);
}
