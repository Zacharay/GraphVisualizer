#include "algorithms/BFSAlgorithm.hpp"

#include "animations/VisitEdge.hpp"
#include "animations/VisitNode.hpp"

void BFSAlgorithm::start(int startingNode) {
    m_isRunning = true;
    m_visited[startingNode] = true;
    m_layout->setNodeColor(startingNode,glm::vec3(1.0f,1.0f,0));

    for (auto edge : m_graph.adjList[startingNode]) {
        m_queue.push(edge);
    }
}
std::vector<std::shared_ptr<VisualizationEvent>> BFSAlgorithm::step() {
    std::vector<std::shared_ptr<VisualizationEvent>> events;

    if (m_queue.empty()) {
        m_isRunning = false;
        return events;
    }

    auto edge = m_queue.front();
    m_queue.pop();

    int nextNode = edge->destination;

    if (m_visited[nextNode]) {
        return events;
    }

    events.push_back(std::make_shared<VisitEdge>(edge));
    events.push_back(std::make_shared<VisitNode>(nextNode));
    m_visited[nextNode] = true;

    for (auto& e : m_graph.adjList[nextNode]) {
        if (!m_visited[e->destination]) {
            m_queue.push(e);

        }
    }

    return events;
}

