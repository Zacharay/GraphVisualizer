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
    const std::vector<std::vector<Edge>> edges = m_layout->getEdges();
    for(int from=0;from<edges.size();from++) {
        for(const Edge &edge :edges[from]) {
            const Node &nodeFrom = m_layout->getNodes()[from];
            const Node &nodeTo = m_layout->getNodes()[edge.destination];

            m_renderer.drawLine(glm::vec3(nodeFrom.posX,nodeFrom.posY,1.0f),glm::vec3(nodeTo.posX,nodeTo.posY,1.0f),glm::vec3(0.0f,0.0f,1.0f));
        }
    }
}
