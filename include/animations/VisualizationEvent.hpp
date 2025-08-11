#pragma once
#include "render/GraphRenderer.hpp"

class GraphLayout;
class GraphRenderer;

class VisualizationEvent {
public:
    float startTime = 0.0f;
    virtual void apply(GraphLayout &layout)=0;
    virtual void render(GraphRenderer &renderer,GraphLayout &layout,float time,float animationSpeed)=0;
};
