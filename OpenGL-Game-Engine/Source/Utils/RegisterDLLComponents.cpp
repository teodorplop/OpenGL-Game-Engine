#include "RegisterDLLComponents.h"

#include "../ComponentSystem.h"
#include "../MeshRenderer.h"
#include "../Camera.h"

void RegisterDLLComponents::Register() {
	ComponentSystem::Register("MeshRenderer", []() -> Component* { return new MeshRenderer(); });
	ComponentSystem::Register("Camera", []() -> Component* { return new Camera(); });
}
