#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW\glfw3.h>

namespace pongEngine { namespace graphics {
	class Window {
	private:
		const char* m_Title;
		GLFWwindow* m_Window;
	public:
		Window(const char* title, int width, int height);
		~Window();
		void getSize(int* width, int* height) const;
		int getWidth() const;
		int getHeight() const;
		void clear() const;
		void update() const;
		bool closed() const;
	private:
		bool init(int width, int height);
	};
} }