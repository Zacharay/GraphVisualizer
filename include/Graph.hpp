#pragma once
#include <vector>
#include "glm/glm.hpp"
struct Edge{
    int weight;
    int destination;
    bool isBidirectional;
    glm::vec3 color;
    Edge()
    {
        weight = 0;
        destination = -1;
        isBidirectional = false;
        color = glm::vec3(1.0f, 1.0f, 1.0f);
    };
    Edge( int destination, int weight,bool isBidirectional,glm::vec3 color)
    {
        this->weight = weight;
        this->destination = destination;
        this->isBidirectional = isBidirectional;
        this->color = color;
    }
};



class Graph{
public:
    std::vector<std::vector<Edge>>adjList;
    Graph(int graphSize);
    void addEdge(int from,int to,int weight=0,bool isBidirectional=false,glm::vec3 color=glm::vec3(1.0f, 1.0f, 1.0f));
    void resize(int numberOfNodes);
    unsigned int getSize()const;
    void printGraph()const;
};