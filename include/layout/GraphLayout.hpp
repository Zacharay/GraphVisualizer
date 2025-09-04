#pragma once
#include <core/Graph.hpp>
#include <iostream>
#include <ostream>
#include <vector>
#include "glm/glm.hpp"

struct Node {
    float posX;
    float posY;
    glm::vec3 color;
    std::string label;
    Node(float x,float y,glm::vec3 color) {
        this->posX = x;
        this->posY = y;
        this->color = color;
        this->label = "";
    }
    Node() {
        this->posX = 0.0f;
        this->posY = 0.0f;
        this->color = glm::vec3(0.0f);
        this->label = "";
    }
};
class GraphLayout {
private:
    std::vector<Node>m_nodes;
    Graph& m_graph;
public:
    GraphLayout(unsigned int nodeCount,Graph &g);
    void randomShuffleNodes();
    void nodesAtCircle(float circleRadius);
    const std::vector<Node>& getNodes() { return m_nodes; }
    const std::vector<std::vector<std::shared_ptr<Edge>>> &getEdges() {return m_graph.adjList;}
    void setNodeColor(int nodeIndex,const glm::vec3 &newColor);
    void setNodePosition(unsigned int nodeIndex,float x,float y);
    void setNodeLabel(unsigned int nodeIndex,std::string label);
    void addNewNode(float posX,float posY);
    int getNodeIdxByCoordinates(float x,float y)const;
    float randJitter(const float maxJitter = 50.0f);
    void reset();
};