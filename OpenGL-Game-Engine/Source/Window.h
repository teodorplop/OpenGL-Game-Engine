#pragma once

#include <include/gl.h>

// Simple window class, contains a title, width and height.
class Window {
private:
	const char* title;
	int width, height;
	bool fullscreen;
	GLFWwindow* window;

	bool Init();

public:
	Window(const char* title, int width, int height, bool fullscreen);
	void SetResolution(int width, int height);

	// Returns true if we received a close window action
	bool Closed();

	// Things used for rendering
	void PollEvents();
	void SwapBuffers();

	int GetWidth();
	int GetHeight();
	GLFWwindow* GetGLFWWindow();
};

