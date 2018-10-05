#include "Application.h"
#include "Menu/MenuScene.h"

Application::Application() : m_window(800, 600) {
    m_window.setScene(std::make_shared<MenuScene>(getWindow()));
}

GameWindow& Application::getWindow() {
    return m_window;
}

Application& Application::get() {
    static Application app;
    return app;
}

int Application::run() {
    return m_window.run();
}
