#include "algorithms/DFSAlgorithm.hpp"

#include "animations/VisitEdge.hpp"
#include "animations/VisitNode.hpp"
#include "GLFW/glfw3.h"

void DFSAlgorithm::start(int startingNode) {
    m_isRunning = true;
    m_visited[startingNode] = true;
    m_layout->setNodeColor(startingNode,glm::vec3(1.0f,1.0f,0));

    for (auto edge : m_graph.adjList[startingNode]) {
        m_dfsStack.push(edge);
    }
}
std::vector<std::shared_ptr<VisualizationEvent>> DFSAlgorithm::step() {

    std::vector<std::shared_ptr<VisualizationEvent>> events;
    if ( m_dfsStack.empty()) {
        m_isRunning = false;
        return events;
    }

    std::shared_ptr<Edge> edge = m_dfsStack.top();
    int nextNodeIndex = edge->destination;
    m_dfsStack.pop();

    if (m_visited[nextNodeIndex]) {
        m_dfsStack.pop();
        return events;
    }

    events.push_back(std::make_shared<VisitEdge>(edge));
    events.push_back(std::make_shared<VisitNode>(nextNodeIndex));
    m_visited[nextNodeIndex] = true;


    for (auto& e : m_graph.adjList[nextNodeIndex]) {
        if (!m_visited[e->destination]) {
            m_dfsStack.push(e);
        }
    }
    return events;
}
