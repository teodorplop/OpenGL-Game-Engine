#include "Application.h"

#include <iostream>
#include <include/gl.h>

#include "Utils\RegisterDLLComponents.h"

#include "Input.h"
#include "Time.h"
#include "ComponentSystem.h"
#include "Camera.h"

Application* Application::Create(const char* windowName, int width, int height, bool fullscreen) {
	return new Application(windowName, width, height, fullscreen);
}

Application::Application(const char* windowName, int width, int height, bool fullscreen) {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize glfw. Quit...");
		Sleep(2000);
		exit(1);
	}

	this->window = new Window(windowName, width, height, fullscreen);
	this->desiredDeltaTime = 1.0f / 60.0f;

	if (!this->window->GetGLFWWindow()) {
		fprintf(stderr, "Quit...");
		Sleep(2000);
		Quit();
		exit(1);
	}

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Failed to initialize glew. Error: %s\n", glewGetErrorString(err));
		Sleep(2000);
		exit(1);
	}

	RegisterDLLComponents::Register();
}

void Application::Run() {
	Input::Handle(window);

	glEnable(GL_DEPTH_TEST);

	float lastFrameTime = 0.0f;
	while (!window->Closed()) {
		float time = (float)glfwGetTime();
		if (time - lastFrameTime < desiredDeltaTime)
			continue;

		// First update the time
		Time::Update(time);

		// Then we update each registered object
		ComponentSystem::Update();

		// Render all cameras
		Camera::Render();

		// Input needs to know when the frame ends, in order to clear its stuff
		Input::EndOfFrame();

		window->PollEvents();
		window->SwapBuffers();
	}
}

void Application::Quit() {
	if (window) {
		delete window;
		window = nullptr;
	}
	glfwTerminate();
}