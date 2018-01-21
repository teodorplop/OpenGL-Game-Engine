#include "Component.h"

#include "GameObject.h"

Transform* Component::GetTransform() const {
	return gameObject->GetTransform();
}

GameObject* Component::GetGameObject() const {
	return gameObject;
}

void Component::Start() {}

void Component::Update() {}

void Component::OnDestroy() {}

void Component::OnCollision(GameObject* other) {}

void Component::Deserialize(const std::string& serializedState) {}

void Component::Enable(bool enabled) {
	this->enabled = enabled;
}

bool Component::IsEnabled() const {
	return enabled;
}