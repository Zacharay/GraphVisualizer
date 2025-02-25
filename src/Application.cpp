#include  "Application.hpp"
#include "Shader.hpp"
#include <memory>


Application::Application() : Window(),m_graph(0){
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);



    m_graphParser.loadGraph(m_graph);

    m_graphRenderer = std::make_unique<GraphRenderer>(m_graph,m_renderer);
    // m_graphRenderer->randomShuffleNodes();
    m_graphRenderer->nodesAtCircle(400.0f);
}
void Application::processInput(float deltaTime) {
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window,true);
    }
    else if(glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        m_graphRenderer->startDfs(0);
    }
}


void Application::onRender() {
    m_graphRenderer->render();
}
void Application::onUpdate() {
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame ;


    processInput(deltaTime);

    m_graphRenderer->updateDfs();
}
