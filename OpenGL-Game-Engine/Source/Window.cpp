#include "Window.h"

#include <cstdio>

Window::Window(const char* title, int width, int height) {
	this->title = title, this->width = width, this->height = height;
	Init();
}

bool Window::Init() {
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to create GLFW window!");
		return false;
	}

	// Center window - because why not?
	GLFWvidmode *mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, (mode->width - width) / 2, (mode->height - height) / 2);

	glfwMakeContextCurrent(window);
	return true;
}

void Window::PollEvents() {
	glfwPollEvents();
}

void Window::SwapBuffers() {
	glfwSwapBuffers(window);
}

bool Window::Closed() {
	return glfwWindowShouldClose(window) == 1 ? true : false;
}

int Window::GetWidth() {
	return width;
}
int Window::GetHeight() {
	return height;
}
GLFWwindow* Window::GetGLFWWindow() {
	return window;
}