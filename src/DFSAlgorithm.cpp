#include "DFSAlgorithm.hpp"

#include <iostream>
#include <ostream>


#include "GLFW/glfw3.h"

void DFSAlgorithm::start(int startingNode) {
    if(m_isRunning)return;

    m_isRunning = true;
    m_dfsStack.push(startingNode);
}
void DFSAlgorithm::update() {
    static double lastUpdateTime = glfwGetTime(); // Track last update time
    double currentTime = glfwGetTime();

    if(!m_isRunning || m_dfsStack.empty())return;

    int parentNodeIndex = m_dfsStack.top();

    //if node was already visited ignore it with timing mechanism
    if (m_visited[parentNodeIndex] == true) {
        lastUpdateTime = glfwGetTime();
        m_dfsStack.pop();
        return;
    }

    // Only update DFS if 100ms have passed since last update
    if (currentTime - lastUpdateTime < 1.0 ) return;
    lastUpdateTime = currentTime; // Reset timer

    m_layout->setNodeColor(parentNodeIndex,glm::vec3(1.0f,0,0));
    m_visited[parentNodeIndex] = true;
    m_dfsStack.pop();

    for(Edge &edge:m_graph.adjList[parentNodeIndex]) {
        if(! m_visited[edge.destination]) {
            m_dfsStack.push(edge.destination);
        }
    }

}