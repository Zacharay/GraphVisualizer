#include <DFSAlgorithm.hpp>
#include <memory>
#include "Window.hpp"
#include "Renderer.hpp"
#include "Graph.hpp"
#include "GraphParser.hpp"
#include "GraphRenderer.hpp"
#include "GraphController.hpp"

class Application : public Window{
    Renderer m_renderer;
    Graph m_graph;
    GraphController m_graphController;
    std::unique_ptr<DFSAlgorithm> dfs;
    GraphParser m_graphParser;
    std::unique_ptr<GraphRenderer> m_graphRenderer;
    std::shared_ptr<GraphLayout> m_graphLayout;
    void processInput(float deltaTime);
public:
    Application();
protected:

    void onMouseButton(int button, int action, int mods) override;
    void onUpdate()override;
    void onRender()override;
};
