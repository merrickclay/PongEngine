#include "Input.h"

namespace pongEngine {
	bool Input::IsKeyPressed(int key) {
		return glfwGetKey(glfwGetCurrentContext(), key);
	}

	bool Input::IsMouseButtonPressed(int button) {
		return glfwGetMouseButton(glfwGetCurrentContext(), button);
	}

	math::vec2 Input::GetMousePosition() {
		double x, y;
		glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);
		return math::vec2(x, y);
	}
}