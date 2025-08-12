#pragma once
#include <memory>
#include <render/Renderer.hpp>
#include "layout/GraphLayout.hpp"
#include "TextRenderer.hpp"
#include "animations/VisualizationEvent.hpp"

class VisualizationEvent;

class GraphRenderer {
private:
    std::shared_ptr<GraphLayout> m_layout;
    Renderer m_renderer;
    TextRenderer m_textRenderer;

    void drawNodes();
    void drawEdges(float animationSpeed);
    void drawEdgeWeight(const glm::vec2 &edgeFrom,const glm::vec2 &edgeTo,const std::string &weight);


public:
    GraphRenderer(std::shared_ptr<GraphLayout> g,Renderer &r):m_layout(g),m_renderer(r) {};
    void render(std::vector<std::shared_ptr<VisualizationEvent>>& events,float animationSpeed,float time);
    void drawEdge(const glm::vec2 &from, const glm::vec2 &to, const std::shared_ptr<Edge> &edge, float progress);
};