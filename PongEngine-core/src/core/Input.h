#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace pongEngine {
	class Input {
	public:
		static bool IsKeyPressed(int key);
		static bool IsMouseButtonPressed(int button);
		static glm::vec2 GetMousePosition();
	};
}