#include "Input.h"

#include <include\gl.h>
#include <include\glm.h>

Window* Input::window = NULL;
float Input::scroll;
glm::vec2 Input::mousePosition;

int Input::keysCount = 512;
bool* Input::keysDown = new bool[Input::keysCount];
bool* Input::keys = new bool[Input::keysCount];
bool* Input::keysUp = new bool[Input::keysCount];

int Input::mouseButtonsCount = 3;
bool* Input::mouseButtonsDown = new bool[Input::mouseButtonsCount];
bool* Input::mouseButtons = new bool[Input::mouseButtonsCount];
bool* Input::mouseButtonsUp = new bool[Input::mouseButtonsCount];

void Input::Handle(Window* window) {
	if (Input::window != NULL) {
		// If we have been handling input for some window, make sure we clear that.
		glfwSetScrollCallback(Input::window->GetGLFWWindow(), NULL);
		glfwSetCursorPosCallback(Input::window->GetGLFWWindow(), NULL);
		glfwSetMouseButtonCallback(Input::window->GetGLFWWindow(), NULL);
		glfwSetKeyCallback(Input::window->GetGLFWWindow(), NULL);

		Input::window = NULL;
	}

	Input::window = window;
	GLFWwindow *glWindow = window->GetGLFWWindow();

	// Make sure we clear input when changing windows
	ClearInput();

	glfwSetScrollCallback(glWindow, ScrollCallback);
	glfwSetCursorPosCallback(glWindow, CursorPositionCallback);
	glfwSetMouseButtonCallback(glWindow, MouseButtonCallback);
	glfwSetKeyCallback(glWindow, KeyCallback);
}
void Input::ClearInput() {
	scroll = 0.0f;

	memset(keysDown, false, keysCount);
	memset(keys, false, keysCount);
	memset(keysUp, false, keysCount);

	memset(mouseButtonsDown, false, mouseButtonsCount);
	memset(mouseButtons, false, mouseButtonsCount);
	memset(mouseButtonsUp, false, mouseButtonsCount);
}
void Input::EndOfFrame() {
	scroll = 0.0f;

	memset(keysDown, false, keysCount);
	memset(keysUp, false, keysCount);

	memset(mouseButtonsDown, false, mouseButtonsCount);
	memset(mouseButtonsUp, false, mouseButtonsCount);
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == 0 && keys[key]) {
		keys[key] = keysDown[key] = false;
		keysUp[key] = true;
	}
	else if (action == 1) {
		keys[key] = keysDown[key] = true;
	}
}
bool Input::GetKeyDown(int key) {
	return keysDown[key];
}
bool Input::GetKey(int key) {
	return keys[key];
}
bool Input::GetKeyUp(int key) {
	return keysUp[key];
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (action == 0) {
		mouseButtons[button] = mouseButtonsDown[button] = false;
		mouseButtonsUp[button] = true;
	}
	else if (action == 1) {
		mouseButtons[button] = mouseButtonsDown[button] = true;
	}
}
bool Input::GetMouseButtonDown(int button) {
	return mouseButtonsDown[button];
}
bool Input::GetMouseButton(int button) {
	return mouseButtons[button];
}
bool Input::GetMouseButtonUp(int button) {
	return mouseButtonsUp[button];
}

void Input::ScrollCallback(GLFWwindow* window, double xOffSet, double yOffSet) {
	scroll = (float)yOffSet;
}
float Input::GetScrollWheel() {
	return scroll;
}

void Input::CursorPositionCallback(GLFWwindow* window, double x, double y) {
	mousePosition.x = (float)x, mousePosition.y = (float)Input::window->GetHeight() - (float)y;
}
glm::vec2 Input::GetMousePosition() {
	return mousePosition;
}