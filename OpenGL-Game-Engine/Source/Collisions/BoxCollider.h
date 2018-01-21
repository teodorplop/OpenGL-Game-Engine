#pragma once

#include "../Component.h"
#include <include\glm.h>
#include "../Export.h"

class CollisionManager;

class BoxCollider : public Component {
	friend class CollisionManager;

private:
	glm::vec3 center;
	glm::vec3 size;

protected:
	void Deserialize(const std::string& serializedState);

public:
	BoxCollider();
	~BoxCollider();
};
