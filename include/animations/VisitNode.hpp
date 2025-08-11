#include "VisualizationEvent.hpp"


class VisitNode : public VisualizationEvent {
    int nodeIndex= -1;
public:
    VisitNode(int nodeIndex){
        this->nodeIndex = nodeIndex;
    }
    void apply(GraphLayout &layout)override {
        layout.setNodeColor(nodeIndex,glm::vec3(1.0f,0.0f,0.0f));
    }
    void render(GraphRenderer &renderer,GraphLayout &layout,float time,float animationSpeed) override{}
};