#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.h"


namespace pongEngine {

	void onFrameBufferResize(GLFWwindow* window, int width, int height);

	Window::Window(const std::string& title, int width, int height) {
		m_Title = title;
		if (!init(width, height)) {
			glfwTerminate();
		}
	}

	Window::~Window() {
		glfwDestroyWindow(m_Window);
	}

	bool Window::init(int width, int height) {
		m_Window = glfwCreateWindow(width, height, m_Title.c_str(), NULL, NULL);
		if (!m_Window) {
			std::cerr << "GLFW window creation failed" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1);
		glfwSetFramebufferSizeCallback(m_Window, Window::onFrameBufferResize);

		if (glewInit() != GLEW_OK) {
			std::cerr << "GLEW initialization failed" << std::endl;
			return false;
		}
		else {
			std::cout << "GLEW initialization succeeded" << std::endl;
		}
		
		std::cout << "OpenGl " << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	void Window::GetSize(int* width, int* height) const {
		glfwGetWindowSize(m_Window, width, height);
	}

	int Window::GetWidth() const {
		int width, height;
		GetSize(&width, &height);
		return width;
	}

	int Window::GetHeight() const {
		int width, height;
		GetSize(&width, &height);
		return height;
	}

	void Window::Clear() const {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::Update() const {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::Closed() const{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::onFrameBufferResize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

} 