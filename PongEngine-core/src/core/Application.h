#pragma once

#include "window.h"

namespace pongEngine {
    class Application
    {
    public:
        Application(const std::string& name = "Hazel App");
        ~Application();
        static Application& GetInstance()
        {
            return *s_Instance;
        };
        Window& GetWindow();
    private:
        static Application* s_Instance;
        Window* m_Window;
    };
}