#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW\glfw3.h>

namespace pongEngine {
	class Window {
	private:
		std::string m_Title;
		GLFWwindow* m_Window;
	public:
		Window(const std::string& title="Pong Engine", int width=640, int height=480);
		~Window();
		void GetSize(int* width, int* height) const;
		int GetWidth() const;
		int GetHeight() const;
		void Clear() const;
		void Update() const;
		bool Closed() const;
	private:
		bool init(int width, int height);
		static void onFrameBufferResize(GLFWwindow* window, int width, int height);
	};
}