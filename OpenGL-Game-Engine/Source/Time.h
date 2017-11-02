#pragma once

#include "Export.h"

class Time {
private:
	static float lastFrameTime;
	static float deltaTime;

public:
	static void Update(float time);

	OPENGL_ENGINE_API static float RealtimeSinceStartup();
	OPENGL_ENGINE_API static float DeltaTime();
};
