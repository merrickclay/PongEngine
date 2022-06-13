#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../math/vec2.h"
namespace pongEngine {
	class Input {
	public:
		static bool IsKeyPressed(int key);
		static bool IsMouseButtonPressed(int button);
		static math::vec2 GetMousePosition();
	};
}