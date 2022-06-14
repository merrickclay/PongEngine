#include <iostream>

#include "src/core/application.h"
#include "src/core/input.h"
#include "src/math/vec2.h"
#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"
#include "src/math/math.h"

void error_callback(int error, const char* description);

int main() {
	using namespace pongEngine;
	using namespace math;
	using namespace graphics;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		std::cerr << "GLFW initialization failed" << std::endl;
	}
	else {
		std::cout << "GLFW initialization succeeded" << std::endl;
	}

	Application app = Application("Pong Engine");
	Window currWindow = app.GetInstance().GetWindow();

	glClearColor(0.0666667f, 0.0745098f, 0.0745088f, 1.0f);

	GLfloat vertices[] = {
		4,  3, 0,
		12, 3, 0,
		4,  6, 0,
		4,  6, 0,
		12, 6, 0,
		12, 3, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniform("pr_matrix", ortho);
	shader.setUniform("colorIn", vec4(0.5, 0.7, 0.3, 1.0));

	while (!currWindow.Closed()) {
		currWindow.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		currWindow.Update();
	}

	glfwTerminate();
	return 0;
}

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}