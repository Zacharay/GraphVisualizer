#pragma once
#include <memory>
#include <vector>
#include "glm/glm.hpp"
#include <chrono>
struct Edge {
    int weight;
    int destination;
    bool isBidirectional;
    std::shared_ptr<Edge> twin; // same edge in opposite direction
    std::chrono::time_point<std::chrono::high_resolution_clock> activation_time;

    // Default constructor
    Edge()
        : weight(0), destination(-1), isBidirectional(false),
          activation_time(std::chrono::high_resolution_clock::time_point(std::chrono::high_resolution_clock::duration(-1)))
    {}

    // Parameterized constructor
    Edge(int destination, int weight, bool isBidirectional)
        : weight(weight), destination(destination), isBidirectional(isBidirectional),
          activation_time(std::chrono::high_resolution_clock::time_point(std::chrono::high_resolution_clock::duration(-1)))
    {}

    bool isActivated() const {
        auto invalid_duration = std::chrono::high_resolution_clock::duration(-1);
        return activation_time.time_since_epoch() != invalid_duration;
    }
};



class Graph{
public:
    std::vector<std::vector<std::shared_ptr<Edge>>>adjList;
    Graph(int graphSize);
    void addEdge(int from,int to,int weight=0,bool isBidirectional=false);
    void resize(int numberOfNodes);
    unsigned int getSize()const;
    void printGraph()const;
};