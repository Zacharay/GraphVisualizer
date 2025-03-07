#include "DFSAlgorithm.hpp"
#include "GLFW/glfw3.h"

void DFSAlgorithm::start(int startingNode) {
    if (m_isRunning) return;

    m_isRunning = true;

    m_visited[startingNode] = true;
    m_layout->setNodeColor(startingNode,glm::vec3(1.0f,0,0));

    for (auto edge : m_graph.adjList[startingNode]) {
        m_dfsStack.push(edge);
    }
}
void DFSAlgorithm::update() {
    static double lastUpdateTime = glfwGetTime(); // Track last update time
    double currentTime = glfwGetTime();

    if(!m_isRunning || m_dfsStack.empty())return;

    std::shared_ptr<Edge> edge = m_dfsStack.top();
    int parentNodeIndex = edge->destination;



    //if node was already visited ignore it with timing mechanism
    if (m_visited[parentNodeIndex] == true) {
        lastUpdateTime = glfwGetTime();
        m_dfsStack.pop();
        return;
    }

    if (!edge->isActivated()) {
        edge->activation_time = std::chrono::high_resolution_clock::now();
    }

    if (currentTime - lastUpdateTime < 1.0 ) return;
        lastUpdateTime = currentTime; // Reset timer

    m_layout->setNodeColor(parentNodeIndex,glm::vec3(1.0f,0,0));

    edge->color = glm::vec3(0,0.5f,0.0);
    if(edge->isBidirectional) {
        edge->twin->color = glm::vec3(0.0f,0.5f,0.0f);
    }
    m_visited[parentNodeIndex] = true;
    m_dfsStack.pop();

    for(auto edge : m_graph.adjList[parentNodeIndex]) {
        if(! m_visited[edge->destination]) {
            m_dfsStack.push(edge);

        }
    }

}