#include <memory>
#include <glm/matrix.hpp>
#include "Window.hpp"
#include "Renderer.hpp"
#include "Graph.hpp"
#include "GraphParser.hpp"
#include "GraphRenderer.hpp"

class Application : public Window{
    Renderer m_renderer;
    Graph m_graph;
    GraphParser m_graphParser;
    std::unique_ptr<GraphRenderer> m_graphRenderer;
    void processInput(float deltaTime);
public:
    Application();
protected:

    void onUpdate()override;
    void onRender()override;
};
