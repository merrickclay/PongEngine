#include <iostream>

#include "src/core/Application.h"
#include "src/core/Input.h"

void error_callback(int error, const char* description);

int main() {
	using namespace pongEngine;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		std::cerr << "GLFW initialization failed" << std::endl;
	}
	else {
		std::cout << "GLFW initialization succeeded" << std::endl;
	}

	Application app = Application("Pong Engine");
	Window currWindow = app.GetInstance().GetWindow();
	while (!currWindow.Closed()) {
		currWindow.Clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f, 0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		currWindow.Update();
	}

	glfwTerminate();
	return 0;
}

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}