#include "Light.h"

#include "Transfom.h"
#include "Utils\Parser.h"

using namespace glm;
using namespace std;

vector<Light*>* Light::lights = new vector<Light*>();

void Light::Deserialize(const std::string& serializedState) {
	Parser* p = Parser::Create(serializedState);

	string type = p->NextWord();
	if (type == "Directional") {
		SetDirectional(p->NextColor());
	}

	Parser::Destroy(p);
}

void Light::Start() {
	lights->push_back(this);
}

void Light::OnDestroy() {
	int idx = 0;
	while (idx < lights->size() && (*lights)[idx] != this)
		++idx;
	lights->erase(lights->begin() + idx);
}

const std::vector<Light*>* const Light::GetLights() {
	return lights;
}

void Light::SetDirectional(Color color) {
	this->color = color;
}

vec4 Light::GetPosition() {
	vec3 pos;
	if (type == Type::Directional)
		pos = GetTransform()->GetForward();
	else
		pos = GetTransform()->GetPosition();
	return vec4(pos.x, pos.y, pos.z, type == Type::Directional ? 0 : 1);
}

Color Light::GetColor() {
	return color;
}