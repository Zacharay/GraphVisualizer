
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <string>

enum AlgorithmState {
    RUNNING,
    STEP,
    RESET,
    IDLE
};

struct VisualizationSettings {
    bool highlightVisited = true;
    bool showTraversalOrder = true;
    bool markActivatedEdges = true;

    AlgorithmState state = AlgorithmState::IDLE;
};

class GUI {
private:
    VisualizationSettings m_settings;
public:
    GUI() {}

    void renderGUI();

    const VisualizationSettings& getSettings() const {
        return m_settings;
    }
    void setIdleAlgorithmState() {
        m_settings.state = AlgorithmState::IDLE;
    }
};
