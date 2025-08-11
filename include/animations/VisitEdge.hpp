#include "VisualizationEvent.hpp"

class VisitEdge : public VisualizationEvent {

public:
    std::shared_ptr<Edge> edge;
    VisitEdge(std::shared_ptr<Edge> edge) : edge(edge) {}

    void apply(GraphLayout &layout)override {
        if (edge) {
            edge->skipDraw = true;

            if (edge->twin) {
                edge->twin->skipDraw = true;
            }
        }
    }
    void render(GraphRenderer &renderer,GraphLayout &layout,float time,float animationSpeed)override {
        float progress = calculateAnimationProgress(animationSpeed,time);

        const Node &nodeFrom = layout.getNodes()[edge->source];
        const Node &nodeTo = layout.getNodes()[edge->destination];
        renderer.drawEdge(glm::vec2(nodeFrom.posX,nodeFrom.posY),glm::vec2(nodeTo.posX,nodeTo.posY),edge,progress);
    }
    float calculateAnimationProgress(float animationSpeed,float currentTime) {
        float elapsed = static_cast<float>(currentTime - startTime);

        //return 1.0f;

        if (elapsed/animationSpeed > 1.0f)return 1.0f;
        else return elapsed / animationSpeed;
    }
};