#include  "Application.hpp"
#include "Shader.hpp"
#include <memory>


Application::Application() : Window(),m_graph(8){
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    m_graph.addEdge(1,2,0,true);
    m_graph.addEdge(2,3,0,true);
    m_graph.addEdge(2,4,0,true);
    m_graph.addEdge(3,4,0,true);
    m_graph.addEdge(3,7,0,true);
    m_graph.addEdge(7,6,0,true);
    m_graph.addEdge(6,5,0,true);

    m_graph.printGraph();
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
