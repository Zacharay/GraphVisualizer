#include "GraphRenderer.hpp"

#include <iostream>
#include <ostream>
#include <random>

#include "Config.hpp"
#include "Window.hpp"

void GraphRenderer::randomShuffleNodes() {
    std::random_device rd;
    std::mt19937 gen(rd());

    const unsigned int windowWidth = Config::getInstance().getWindowWidth();
    const unsigned int windowHeight = Config::getInstance().getWindowHeight();

    std::uniform_int_distribution<int> dis(0, windowWidth);
    std::uniform_int_distribution<int> dis2(0, windowHeight);

    for(Node &node:m_nodes) {
        int posX = dis(gen);
        int posY = dis2(gen);
        glm::vec3 color(0.0f,1.0f,0.0f);

        node.posX=posX;
        node.posY=posY;
        node.color=color;
    }
}
void GraphRenderer::nodesAtCircle(float circleRadius) {
    unsigned int numNodes = m_nodes.size();

    float theta = 0.0f;
    float thetaStep = 2.0f*M_PI/numNodes;

    const unsigned int windowWidth = Config::getInstance().getWindowWidth();
    const unsigned int windowHeight = Config::getInstance().getWindowHeight();

    for(Node &node:m_nodes) {
        float x = circleRadius*cosf(theta);
        float y = circleRadius*sinf(theta);

        node.posX = x + windowWidth/2;
        node.posY = y + windowHeight/2;
        node.color = glm::vec3(0.0f,0.5f,0.0f);
        theta += thetaStep;
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

