#pragma once
#include <memory>
#include <vector>
#include "glm/glm.hpp"
#include <chrono>
struct Edge {
    int weight;
    int destination;
    int source;
    bool isBidirectional;
    bool skipDraw = false;
    std::shared_ptr<Edge> twin; // same edge in opposite direction

    // Default constructor
    Edge()
        : weight(0), destination(-1),source(-1), isBidirectional(false)
    {}

    // Parameterized constructor
    Edge(int source,int destination, int weight, bool isBidirectional)
        : source(source),weight(weight), destination(destination), isBidirectional(isBidirectional)
    {}
};



class Graph{
public:
    std::vector<std::vector<std::shared_ptr<Edge>>>adjList;
    Graph(int graphSize);
    void addEdge(int from,int to,int weight=0,bool isBidirectional=false);
    void addNewNode();
    void resize(int numberOfNodes);
    unsigned int getSize()const;
    void printGraph()const;
private:
    bool doesEdgeExist(int from,int to);
};