#include <algorithms/DFSAlgorithm.hpp>
#include <memory>
#include "core/Window.hpp"
#include "render/Renderer.hpp"
#include "core/Graph.hpp"
#include "utils/GraphParser.hpp"
#include "render/GraphRenderer.hpp"
#include "GraphController.hpp"
#include "layout/GUI.hpp"
#include <memory>
#include "input/IMouseMode.hpp"



class Application : public Window{
    Renderer m_renderer;

    Graph m_graph;
    std::unique_ptr<GraphController> m_graphController;
    std::unique_ptr<DFSAlgorithm> dfs;
    GraphParser m_graphParser;
    std::unique_ptr<GraphRenderer> m_graphRenderer;
    std::shared_ptr<GraphLayout> m_graphLayout;

    std::unique_ptr<IMouseMode> m_activeMouseMode;
    MouseModeType m_currentMouseModeType;

    float lastFrame = 0.0f;

    GUI m_gui;

    void processInput(float deltaTime);
    void updateVisualization(float deltaTime);
    std::unique_ptr<GraphAlgorithm> getSelectedAlgorithm();
public:
    Application();
protected:

    void onCursorPosition(float x, float y) override;
    void onMouseButton(int button, int action, int mods) override;
    void onUpdate()override;
    void onRender()override;

};
