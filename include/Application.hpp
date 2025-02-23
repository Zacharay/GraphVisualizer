#include <memory>
#include <glm/matrix.hpp>
#include "Window.hpp"
#include "Renderer.hpp"
#include "Graph.hpp"
#include "GraphRenderer.hpp"

class Application : public Window{
    Renderer m_renderer;
    Graph m_graph;
    std::unique_ptr<GraphRenderer> m_graphRenderer;
    void processInput(float deltaTime);
public:
    Application();
protected:

    void onUpdate()override;
    void onRender()override;
};
