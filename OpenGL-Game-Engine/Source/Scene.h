#pragma once

#include "Export.h"
#include <string>

class Scene {
	static const std::string& path;

public:
	OPENGL_ENGINE_API static void Load(const char* filename);
};
