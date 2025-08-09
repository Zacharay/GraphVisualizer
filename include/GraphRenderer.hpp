#pragma once
#include <memory>
#include <Renderer.hpp>
#include "GraphLayout.hpp"
#include "TextRenderer.hpp"


class GraphRenderer {
private:
    std::shared_ptr<GraphLayout> m_layout;
    Renderer m_renderer;
    TextRenderer m_textRenderer;

    void drawNodes();
    void drawEdges(float animationSpeed);
    void drawEdge(const glm::vec2 &from, const glm::vec2 &to, const std::shared_ptr<Edge> &edge, float progress);
    void drawEdgeWeight(const glm::vec2 &edgeFrom,const glm::vec2 &edgeTo,const std::string &weight);

    bool shouldSkipEdge(const std::shared_ptr<Edge> &edge) const;
    float calculateAnimationProgress(const std::shared_ptr<Edge> &edge,float animationSpeed)const;

public:
    GraphRenderer(std::shared_ptr<GraphLayout> g,Renderer &r):m_layout(g),m_renderer(r) {};
    void render(const float animationSpeed);
};