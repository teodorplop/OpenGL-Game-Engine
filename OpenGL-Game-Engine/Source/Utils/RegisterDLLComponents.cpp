#include "RegisterDLLComponents.h"

#include "../ComponentSystem.h"
#include "../MeshRenderer.h"

void RegisterDLLComponents::Register() {
	ComponentSystem::Register("MeshRenderer", []() -> Component* { return new MeshRenderer(); });
}
