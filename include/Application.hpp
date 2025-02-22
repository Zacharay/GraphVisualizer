#include <glm/matrix.hpp>
#include "Window.hpp"
#include "Renderer.hpp"
#include "Graph.hpp"
class Application : public Window{
    Renderer m_renderer;
    Graph m_graph;
    void processInput(float deltaTime);
public:
    Application();
protected:

    void onUpdate()override;
    void onRender()override;
};