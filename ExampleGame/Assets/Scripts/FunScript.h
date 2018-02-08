#pragma once

#include <OpenGL-Game-Engine.h>

class FunScript : public Component {
private:
	float moveSpeed;

protected:
	void Update();
	void OnCollision(GameObject* other);
	void Deserialize(const std::string& serializedState);
};