#include "GraphRenderer.hpp"

#include <iostream>
#include <ostream>
#include <random>

#include "Config.hpp"
#include "Window.hpp"


void GraphRenderer::render()  {
    for(const Node &node:m_layout->getNodes()) {
        m_renderer.drawNode(node.posX,node.posY,node.color);
    }
    const std::vector<std::vector<std::shared_ptr<Edge>>> edges = m_layout->getEdges();
    for(int from=0;from<edges.size();from++) {
        for(std::shared_ptr<Edge> edge: edges[from]) {
            const Node &nodeFrom = m_layout->getNodes()[from];
            const Node &nodeTo = m_layout->getNodes()[edge->destination];

            m_renderer.drawLine(glm::vec3(nodeFrom.posX,nodeFrom.posY,1.0f),glm::vec3(nodeTo.posX,nodeTo.posY,1.0f),edge->color);
        }
    }
}
