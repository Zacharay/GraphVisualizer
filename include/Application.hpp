#include <DFSAlgorithm.hpp>
#include <memory>
#include "Window.hpp"
#include "Renderer.hpp"
#include "Graph.hpp"
#include "GraphParser.hpp"
#include "GraphRenderer.hpp"
#include "GraphController.hpp"
#include "GUI.hpp"

enum MouseMode {
    SPAWN_NODES,
    SPAWN_EDGES,
    MOVE
};


class Application : public Window{
    Renderer m_renderer;
    Graph m_graph;
    std::unique_ptr<GraphController> m_graphController;
    std::unique_ptr<DFSAlgorithm> dfs;
    GraphParser m_graphParser;
    std::unique_ptr<GraphRenderer> m_graphRenderer;
    std::shared_ptr<GraphLayout> m_graphLayout;
    GUI m_gui;
    MouseMode m_mouseMode = MouseMode::MOVE;

    //temporary
    bool m_isDragging = false;
    int m_selectedNode = -1;

    void processInput(float deltaTime);
    void updateVisualization();
public:
    Application();
protected:

    void onCursorPosition(float x, float y) override;
    void onMouseButton(int button, int action, int mods) override;
    void onUpdate()override;
    void onRender()override;

};
