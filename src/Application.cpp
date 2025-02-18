#include  "Application.hpp"
#include "Shader.hpp"
#include <memory>







Application::Application() : Window(){
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

}
void Application::processInput(float deltaTime) {
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window,true);
    }
}


void Application::onRender() {
    m_renderer.drawNode(200,200);
    m_renderer.drawNode(400,500);

    m_renderer.drawLine({200.0f,200.0f,0.0f},{400.0f,500.0f,0.0f});
}
void Application::onUpdate() {
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame ;

    processInput(deltaTime);
}
