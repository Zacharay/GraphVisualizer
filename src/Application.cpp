#include  "Application.hpp"
#include "Shader.hpp"
#include <memory>

float startTime = glfwGetTime();
Application::Application() : Window(),m_graph(0){
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    m_graphParser.loadGraph(m_graph);

    m_graphLayout= std::make_shared<GraphLayout>(m_graph.getSize(),m_graph);
    m_graphLayout->nodesAtCircle(400.0f);


    m_graphController = std::make_unique<GraphController>(m_graphLayout);
    m_graphController->setAlgorithm(std::make_unique<DFSAlgorithm>(m_graph,m_graphLayout));
    m_graphRenderer = std::make_unique<GraphRenderer>(m_graphLayout,m_renderer);



}
void Application::processInput(float deltaTime) {
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window,true);
    }
    else if(glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        m_graphController->start(1);
    }
}


void Application::onRender() {
    m_gui.renderGUI();
    m_graphRenderer->render();

}
void Application::onUpdate() {
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame ;

    processInput(deltaTime);

    updateVisualization();

}
void Application::onMouseButton(int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        double xpos, ypos;
        glfwGetCursorPos(m_window, &xpos, &ypos);  // Get mouse position

        if(m_mouseMode == MouseMode::SPAWN_NODES) {
            if(action == GLFW_PRESS) {
                m_graph.addNewNode();
                m_graphLayout->addNewNode(xpos,ypos);
            }
        }
        else if(m_mouseMode == MouseMode::MOVE) {
            if(action==GLFW_PRESS) {
                m_selectedNode = m_graphLayout->getNodeIdxByCoordinates(xpos,ypos);
                m_isDragging = true;
            }
            else if(action == GLFW_RELEASE) {
                m_selectedNode = -1;
                m_isDragging = false;
            }
        }

    }
}
void Application::onCursorPosition(float x, float y) {
    if(m_selectedNode != -1 && m_isDragging) {
        m_graphLayout->setNodePosition(m_selectedNode,x,y);
    }
}
void Application::updateVisualization() {
    VisualizationSettings settings = m_gui.getSettings();


    if (!m_graphController->isRunning() && (settings.state == AlgorithmState::STEP ||  settings.state == AlgorithmState::RUNNING)) {
        m_graphController->start(1);
    }

    if (settings.state == AlgorithmState::STEP) {
        m_graphController->update();
        m_gui.setIdleAlgorithmState();
    }
    else if (settings.state == AlgorithmState::IDLE) {
        m_gui.setIdleAlgorithmState();
    }
    else if (settings.state == AlgorithmState::RUNNING) {
        m_graphController->update();
    }
    else if (settings.state == AlgorithmState::RESET) {
        m_graphLayout->reset();
        m_gui.setIdleAlgorithmState();
    }
}

