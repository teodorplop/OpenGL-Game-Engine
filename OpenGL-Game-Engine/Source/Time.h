#pragma once

class Time {
private:
	static float lastFrameTime;
	static float deltaTime;

public:
	static void Update(float time);

	static float RealtimeSinceStartup();
	static float DeltaTime();
};
