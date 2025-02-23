#pragma once
#include <vector>
#include "glm/glm.hpp"
struct Edge{
    int weight;
    int destination;
    bool isBidirectional;
    Edge()
    {
        weight = 0;
        destination = -1;
        isBidirectional = false;
    };
    Edge( int destination, int weight,bool isBidirectional)
    {
        this->weight = weight;
        this->destination = destination;
        this->isBidirectional = isBidirectional;
    }
};



class Graph{
public:
    std::vector<std::vector<Edge>>adjList;
    Graph(int graphSize);
    void addEdge(int from,int to,int weight=0,bool isBidirectional=false);
    unsigned int getSize()const;
    void printGraph()const;
};