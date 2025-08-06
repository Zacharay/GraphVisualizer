#pragma once
#include <memory>
#include <Renderer.hpp>
#include "GraphLayout.hpp"
#include "Graph.hpp"


class GraphRenderer {
private:
    std::shared_ptr<GraphLayout> m_layout;
    Renderer m_renderer;
public:
    GraphRenderer(std::shared_ptr<GraphLayout> g,Renderer &r):m_layout(g),m_renderer(r) {};
    void render(const float animationSpeed);
};