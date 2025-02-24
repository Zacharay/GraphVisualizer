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

    m_graphRenderer = std::make_unique<GraphRenderer>(m_graph,m_renderer);
    // m_graphRenderer->randomShuffleNodes();
    m_graphRenderer->nodesAtCircle(400.0f);
}
void Application::processInput(float deltaTime) {
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window,true);
    }
}


void Application::onRender() {
    m_graphRenderer->render();
}
void Application::onUpdate() {
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame ;

    processInput(deltaTime);
}
