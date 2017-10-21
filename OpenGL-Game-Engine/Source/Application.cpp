#include "Application.h"

#include <iostream>
#include <include/gl.h>

#include "Input.h"
#include "Time.h"
#include "ComponentSystem.h"

//#include "Renderer.h"

Application::Application(const char* windowName, int width, int height) {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize glfw.");
		Sleep(2000);
		exit(1);
	}

	this->window = new Window(windowName, width, height);
	this->desiredDeltaTime = 1.0f / 60.0f;

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Failed to initialize glew. Error: %s\n", glewGetErrorString(err));
		Sleep(2000);
		exit(1);
	}

	Run();
}

Application::~Application() {
	delete window;
	glfwTerminate();
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

		// Render all registered renderables using this camera
		//Renderer::Render(camera);

		// Input needs to know when the frame ends, in order to clear its stuff
		Input::EndOfFrame();

		window->PollEvents();
		window->SwapBuffers();
	}
	 
	delete this;
}