
#include "application.h"

namespace pongEngine{

	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name) {
		s_Instance = this;
		m_Window = new Window(name);
	}

	Application::~Application() {}

	Window& Application::GetWindow() {
		return *m_Window;
	}
}