#pragma once

#include "Component.h"

class FunScript : public Component {
private:
	float moveSpeed;

protected:
	void Start();
	void Update();
	void OnDestroy();
	void OnCollision(GameObject* other);
	void Deserialize(const std::string& serializedState);
};