#pragma once

#include "Export.h"
#include "Window.h"
#include <include/glm.h>

class Input {
private:
	static Window* window;

	static float scroll;
	static glm::vec2 mousePosition;

	static int keysCount;
	static bool* keysDown;
	static bool* keys;
	static bool* keysUp;

	static int mouseButtonsCount;
	static bool* mouseButtonsDown;
	static bool* mouseButtons;
	static bool* mouseButtonsUp;

	static void ScrollCallback(GLFWwindow* window, double xOffSet, double yOffSet);
	static void CursorPositionCallback(GLFWwindow* window, double x, double y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:
	// Sets the window we want to handle input for
	static void Handle(Window* window);
	// Clear stuff at the end of frame
	static void EndOfFrame();

	// Returns true if we pressed the key THIS FRAME
	OPENGL_ENGINE_API static bool GetKeyDown(int key);
	// Returns true if the key is pressed
	OPENGL_ENGINE_API static bool GetKey(int key);
	// Returns true if we released the key THIS FRAME
	OPENGL_ENGINE_API static bool GetKeyUp(int key);

	// Same, but for mouse buttons
	OPENGL_ENGINE_API static bool GetMouseButtonDown(int button);
	OPENGL_ENGINE_API static bool GetMouseButton(int button);
	OPENGL_ENGINE_API static bool GetMouseButtonUp(int button);

	OPENGL_ENGINE_API static float GetScrollWheel();
	// Returns mouse position in screen coordinates
	OPENGL_ENGINE_API static glm::vec2 GetMousePosition();
};
