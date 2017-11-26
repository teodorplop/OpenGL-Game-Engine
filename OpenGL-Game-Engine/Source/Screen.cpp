#include "Screen.h"
#include <include\gl.h>

Window* Screen::window = nullptr;

void Screen::Handle(Window* window) {
	Screen::window = window;
}

int Screen::GetWidth() {
	return window->GetWidth();
}

int Screen::GetHeight() {
	return window->GetHeight();
}

void Screen::SetResolution(int w, int h) {
	window->SetResolution(w, h);
}

void Screen::EnableCursor(bool enabled) {
	glfwSetInputMode(window->GetGLFWWindow(), GLFW_CURSOR, enabled ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
}