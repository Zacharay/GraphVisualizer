#include "GraphLayout.hpp"
#include <random>
#include "Config.hpp"

GraphLayout::GraphLayout(unsigned int nodeCount, Graph &g):m_graph(g){
    m_nodes.reserve(nodeCount);
    m_nodes.resize(nodeCount);
}

void GraphLayout::randomShuffleNodes() {
    std::random_device rd;
    std::mt19937 gen(rd());

    const unsigned int windowWidth = Config::getInstance().getWindowWidth();
    const unsigned int windowHeight = Config::getInstance().getWindowHeight();
    const unsigned int nodeRadius = Config::getInstance().getNodeRadius();

    std::uniform_int_distribution<int> dis(nodeRadius, windowWidth - nodeRadius);
    std::uniform_int_distribution<int> dis2(nodeRadius, windowHeight-nodeRadius);

    for(Node &node:m_nodes) {
        int posX = dis(gen);
        int posY = dis2(gen);
        glm::vec3 color(0.0f,1.0f,0.0f);

        node.posX=posX;
        node.posY=posY;
        node.color=color;
    }
}
void GraphLayout::nodesAtCircle(float circleRadius) {
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
        node.color = glm::vec3(0.0f,1.0f,0.0f);
        theta += thetaStep;
    }
}
void GraphLayout::setNodeColor(int nodeIndex,const glm::vec3 &newColor) {
    m_nodes[nodeIndex].color = newColor;
}
void GraphLayout::addNewNode(float posX,float posY) {
    m_nodes.emplace_back(posX,posY,glm::vec3(0,1,0));
}