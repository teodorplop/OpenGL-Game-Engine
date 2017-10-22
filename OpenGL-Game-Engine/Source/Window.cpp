#include "Window.h"

#include <cstdio>

Window::Window(const char* title, int width, int height, bool fullscreen) {
	this->title = title, this->width = width, this->height = height, this->fullscreen = fullscreen;
	Init();
}

bool Window::Init() {
	window = glfwCreateWindow(width, height, title, fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
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

void Window::SetResolution(int width, int height) {
	glfwSetWindowSize(window, width, height);
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