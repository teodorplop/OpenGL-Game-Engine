#include "Time.h"

#include <include/gl.h>

float Time::lastFrameTime = 0.0f;
float Time::deltaTime = 0.0f;

void Time::Update(float time) {
	deltaTime = time - lastFrameTime;
	lastFrameTime = time;
}

float Time::DeltaTime() {
	return deltaTime;
}
float Time::RealtimeSinceStartup() {
	return (float)glfwGetTime();
}