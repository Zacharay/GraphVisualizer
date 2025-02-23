#include "GraphRenderer.hpp"

#include <iostream>
#include <ostream>
#include <random>

#include "Window.hpp"

void GraphRenderer::randomShuffleNodes() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, WINDOW_WIDTH);
    std::uniform_int_distribution<int> dis2(0, WINDOW_HEIGHT);

    for(Node &node:m_nodes) {
        int posX = dis(gen);
        int posY = dis2(gen);
        glm::vec3 color(0.0f,1.0f,0.0f);

        node.posX=posX;
        node.posY=posY;
        node.color=color;
    }
}
void GraphRenderer::render()  {
    for(const Node &node:m_nodes) {
        m_renderer.drawNode(node.posX,node.posY);
    }

    for(int from=0;from<m_graph.adjList.size();from++) {
        for(const Edge &edge :m_graph.adjList[from]) {
            const Node &nodeFrom = m_nodes[from];
            const Node &nodeTo = m_nodes[edge.destination];

            m_renderer.drawLine(glm::vec3(nodeFrom.posX,nodeFrom.posY,1.0f),glm::vec3(nodeTo.posX,nodeTo.posY,1.0f));
        }

    }
}

