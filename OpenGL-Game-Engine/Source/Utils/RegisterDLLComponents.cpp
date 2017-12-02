#include "RegisterDLLComponents.h"

#include "../ComponentSystem.h"
#include "../MeshRenderer.h"
#include "../Camera.h"
#include "../Light.h"

void RegisterDLLComponents::Register() {
	ComponentSystem::Register("MeshRenderer", []() -> Component* { return new MeshRenderer(); });
	ComponentSystem::Register("Camera", []() -> Component* { return new Camera(); });
	ComponentSystem::Register("Light", []() -> Component* { return new Light(); });
}
