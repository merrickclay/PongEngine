#include <iostream>


#include "src/graphics/window.h"

void error_callback(int error, const char* description);

int main() {
	using namespace pongEngine;
	using namespace graphics;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		std::cerr << "GLFW initialization failed" << std::endl;
	}
	else {
		std::cout << "GLFW initialization succeeded" << std::endl;
	}

	Window window("Pong Engine", 640, 480);
	while (!window.closed()) {
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f, 0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		window.update();
	}

	glfwTerminate();
	return 0;
}

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}