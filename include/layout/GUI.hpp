#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <string>

#include "input/MouseModeFactory.hpp"

enum AlgorithmState {
    RUNNING,
    STEP,
    RESET,
    IDLE
};

enum AlgorithmGUI {
    DFS,
    BFS,
    DIJKSTRA
};

struct VisualizationSettings {
    bool highlightVisited = true;
    bool showTraversalOrder = true;
    bool markActivatedEdges = true;
    float visualizationSpeed = 1.0f;

    AlgorithmState state = AlgorithmState::IDLE;

};

class GUI {
private:


    VisualizationSettings m_settings;
    int m_selectedAlgorithm  = AlgorithmGUI::DFS;
    int m_startingNode = 1;

    int m_currentMouseModeIdx = 0;
    MouseModeType m_currentMouseMode = MouseModeType::SPAWN_NODES;

public:
    GUI() {}

    void renderGUI(int maxNode);

    const VisualizationSettings& getSettings() const {
        return m_settings;
    }
    void setIdleAlgorithmState() {
        m_settings.state = AlgorithmState::IDLE;
    }
    int getSelectedAlgorithm() const {return m_selectedAlgorithm;}
    int getStartingNode() const {return m_startingNode;}
    MouseModeType getCurrentMouseMode() const {return m_currentMouseMode;}
};
