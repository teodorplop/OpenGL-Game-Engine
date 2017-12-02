#pragma once

#include "Component.h"
#include "Color.h"
#include <include\glm.h>
#include <vector>

#include "Export.h"

class Light : public Component {
public:
	enum Type { Directional };

private:
	static std::vector<Light*>* lights;
	Type type;
	Color color;

protected:
	void Start();
	void OnDestroy();
	void Deserialize(const std::string& serializedState);

public:
	static const std::vector<Light*>* const GetLights();

	OPENGL_ENGINE_API void SetDirectional(Color color);

	glm::vec4 GetPosition();
	OPENGL_ENGINE_API Color GetColor();
};
