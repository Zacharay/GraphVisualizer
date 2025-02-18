#include <glm/matrix.hpp>
#include "Window.hpp"
#include "Renderer.hpp"

class Application : public Window{
    Renderer m_renderer;
    void processInput(float deltaTime);
public:
    Application();
protected:

    void onUpdate()override;
    void onRender()override;
};