#include  "Application.hpp"
#include "Shader.hpp"
#include <memory>

float startTime = glfwGetTime();
Application::Application() : Window(),m_graph(0){
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    m_graphParser.loadGraph(m_graph);

    m_graphLayout= std::make_shared<GraphLayout>(m_graph.getSize(),m_graph);
    m_graphLayout->nodesAtCircle(400.0f);

    m_graphController.setAlgorithm(std::make_unique<DFSAlgorithm>(m_graph,m_graphLayout));
    m_graphRenderer = std::make_unique<GraphRenderer>(m_graphLayout,m_renderer);



}
void Application::processInput(float deltaTime) {
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window,true);
    }
    else if(glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        m_graphController.start(1);
    }
}


void Application::onRender() {
    m_graphRenderer->render();
}
void Application::onUpdate() {
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame ;

    processInput(deltaTime);

    m_graphController.update();
}
void Application::onMouseButton(int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(m_window, &xpos, &ypos);  // Get mouse position

        m_graph.addNewNode();

        m_graphLayout->addNewNode(xpos,ypos);

    }
}
