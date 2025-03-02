#include "DFSAlgorithm.hpp"

#include <iostream>
#include <ostream>


#include "GLFW/glfw3.h"

void DFSAlgorithm::start(int startingNode) {
    if (m_isRunning) return;

    m_isRunning = true;

    // Get reference to first edge of the starting node (assuming it's not empty)
    if (!m_graph.adjList[startingNode].empty()) {
        Edge& edge = m_graph.adjList[startingNode][0]; // Get reference
        m_dfsStack.emplace(&edge); // Store reference
    }
}
void DFSAlgorithm::update() {
    static double lastUpdateTime = glfwGetTime(); // Track last update time
    double currentTime = glfwGetTime();

    if(!m_isRunning || m_dfsStack.empty())return;

    Edge *currentEdge = m_dfsStack.top();
    currentEdge->color = glm::vec3(0,1.0f,0);

    //if node was already visited ignore it with timing mechanism
    if (m_visited[currentEdge->destination] == true) {
        lastUpdateTime = glfwGetTime();
        m_dfsStack.pop();
        return;
    }

    int parentNodeIndex = currentEdge->destination;
    // Only update DFS if 100ms have passed since last update
    if (currentTime - lastUpdateTime < 1.0 ) return;
    lastUpdateTime = currentTime; // Reset timer

    m_layout->setNodeColor(parentNodeIndex,glm::vec3(1.0f,0,0));
    m_visited[parentNodeIndex] = true;
    m_dfsStack.pop();

    for(Edge &edge:m_graph.adjList[parentNodeIndex]) {
        if(! m_visited[edge.destination]) {
            m_dfsStack.push(&edge);
        }
    }

}