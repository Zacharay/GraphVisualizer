#include "algorithms/BFSAlgorithm.hpp"

#include "animations/VisitEdge.hpp"
#include "animations/VisitNode.hpp"

void BFSAlgorithm::start(int startingNode) {

    m_visited[startingNode] = true;
    m_layout->setNodeColor(startingNode,glm::vec3(1.0f,1.0f,0));

    for (auto edge : m_graph.adjList[startingNode]) {
        m_queue.push(edge);
    }
}
std::vector<std::shared_ptr<VisualizationEvent>> BFSAlgorithm::step() {
    std::vector<std::shared_ptr<VisualizationEvent>> events;

    if ( m_queue.empty()) return events;

    std::shared_ptr<Edge> edge = m_queue.front();
    int parentNodeIndex = edge->destination;

    if (m_visited[parentNodeIndex]) {
        m_queue.pop();
        return events;
    }

    events.push_back(std::make_shared<VisitEdge>(edge));
    events.push_back(std::make_shared<VisitNode>(parentNodeIndex));

    m_visited[parentNodeIndex] = true;
    m_queue.pop();

    for (auto& e : m_graph.adjList[parentNodeIndex]) {
        if (!m_visited[e->destination]) {
            m_queue.push(e);
        }
    }

    return events;
}

