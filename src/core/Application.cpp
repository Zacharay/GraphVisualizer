#include  "core/Application.hpp"
#include <memory>

#include "layout/GUI.hpp"
#include "core/GraphController.hpp"
#include "algorithms/BFSAlgorithm.hpp"
#include "render/GraphRenderer.hpp"
#include "input/MouseModeFactory.hpp"

Application::Application() : Window(),m_graph(0){
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    m_graphParser.loadGraph(m_graph);
    m_graph.printGraph();

    m_graphLayout= std::make_shared<GraphLayout>(m_graph.getSize(),m_graph);
    m_graphLayout->nodesAtCircle(400.0f);


    m_graphController = std::make_unique<GraphController>(m_graphLayout);
    m_graphController->setAlgorithm(getSelectedAlgorithm());
    m_graphRenderer = std::make_unique<GraphRenderer>(m_graphLayout,m_renderer);

    m_currentMouseModeType = m_gui.getCurrentMouseMode();
    m_activeMouseMode = MouseModeFactory::create(m_currentMouseModeType,m_graph,*m_graphLayout);

    lastFrame = glfwGetTime();
}
std::unique_ptr<GraphAlgorithm> Application::getSelectedAlgorithm() {
    switch (m_gui.getSelectedAlgorithm()) {
        case AlgorithmGUI::DFS:
            return std::make_unique<DFSAlgorithm>(m_graph,m_graphLayout);
        break;
        case AlgorithmGUI::BFS:
            return std::make_unique<BFSAlgorithm>(m_graph,m_graphLayout);
        break;
        default:
            break;
    }
}
void Application::processInput(float deltaTime) {
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window,true);
    }
}


void Application::onRender() {
    m_gui.renderGUI(m_graph.getSize()-1);
    auto activeEvents = m_graphController->getAnimationController().getActiveEvents();
    m_graphRenderer->render(activeEvents,m_gui.getSettings().visualizationSpeed,m_graphController->getAnimationController().getTime());

}
void Application::onUpdate() {
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame-lastFrame ;
    lastFrame = currentFrame;

    processInput(deltaTime);



    MouseModeType selectedMouseMode = m_gui.getCurrentMouseMode();

    if (selectedMouseMode != m_currentMouseModeType) {
        m_currentMouseModeType = selectedMouseMode;
        m_activeMouseMode = MouseModeFactory::create(m_currentMouseModeType,m_graph,*m_graphLayout);
    }

    updateVisualization(deltaTime);

}
void Application::onMouseButton(int button, int action, int mods) {
        double xpos, ypos;
        glfwGetCursorPos(m_window, &xpos, &ypos);  // Get mouse position


        if (action == GLFW_PRESS) {
            m_activeMouseMode->onMouseDown(button,xpos,ypos);
        }
        else if (action== GLFW_RELEASE) {
            m_activeMouseMode->onMouseUp(button,xpos,ypos);
        }

}
void Application::onCursorPosition(float x, float y) {
    m_activeMouseMode->onMouseMove(x,y);
}
void Application::updateVisualization(float deltaTime) {
    VisualizationSettings settings = m_gui.getSettings();

    const float animationSpeed = settings.visualizationSpeed;

    if (!m_graphController->isRunning() && (settings.state == AlgorithmState::STEP ||  settings.state == AlgorithmState::RUNNING)) {
        m_graphController->setAlgorithm(getSelectedAlgorithm());
        m_graphController->start(m_gui.getStartingNode());
        std::cout<<"xd";
    }

    if (settings.state == AlgorithmState::STEP) {
        m_graphController->update(deltaTime,animationSpeed,true);
        m_gui.setIdleAlgorithmState();
    }
    else if (settings.state == AlgorithmState::IDLE) {
        m_gui.setIdleAlgorithmState();
    }
    else if (settings.state == AlgorithmState::RUNNING) {
        m_graphController->update(deltaTime,animationSpeed);
    }
    else if (settings.state == AlgorithmState::RESET) {
        m_graphLayout->reset();
        m_graphController->resetAlgorithm(getSelectedAlgorithm());
        m_graphController->getAnimationController().resetEvents();
        m_gui.setIdleAlgorithmState();
    }
}

