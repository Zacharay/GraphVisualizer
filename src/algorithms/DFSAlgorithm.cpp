#include "algorithms/DFSAlgorithm.hpp"

#include "animations/VisitEdge.hpp"
#include "animations/VisitNode.hpp"
#include "GLFW/glfw3.h"

void DFSAlgorithm::start(int startingNode) {
    
    m_visited[startingNode] = true;
    m_layout->setNodeColor(startingNode,glm::vec3(1.0f,1.0f,0));

    for (auto edge : m_graph.adjList[startingNode]) {
        m_dfsStack.push(edge);
    }
}
std::vector<std::shared_ptr<VisualizationEvent>> DFSAlgorithm::step() {

    std::vector<std::shared_ptr<VisualizationEvent>> events;
    if ( m_dfsStack.empty()) return events;

    std::shared_ptr<Edge> edge = m_dfsStack.top();
    int parentNodeIndex = edge->destination;


    if (m_visited[parentNodeIndex]) {
        m_dfsStack.pop();
        return events;
    }
    events.push_back(std::make_shared<VisitEdge>(edge));
    events.push_back(std::make_shared<VisitNode>(parentNodeIndex));

    m_visited[parentNodeIndex] = true;
    m_dfsStack.pop();

    for (auto& e : m_graph.adjList[parentNodeIndex]) {
        if (!m_visited[e->destination]) {
            m_dfsStack.push(e);

        }
    }
    return events;
}
