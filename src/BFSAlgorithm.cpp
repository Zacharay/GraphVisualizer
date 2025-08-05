#include "BFSAlgorithm.hpp"

void BFSAlgorithm::start(int startingNode) {

    m_visited[startingNode] = true;
    m_layout->setNodeColor(startingNode,glm::vec3(1.0f,1.0f,0));

    for (auto edge : m_graph.adjList[startingNode]) {
        m_queue.push(edge);
    }
}
std::optional<TraversalStep> BFSAlgorithm::step() {
    if ( m_queue.empty()) return std::nullopt;

    std::shared_ptr<Edge> edge = m_queue.front();
    int parentNodeIndex = edge->destination;

    if (m_visited[parentNodeIndex]) {
        m_queue.pop();
        return std::nullopt;
    }

    m_visited[parentNodeIndex] = true;
    m_queue.pop();

    for (auto& e : m_graph.adjList[parentNodeIndex]) {
        if (!m_visited[e->destination]) {
            m_queue.push(e);
        }
    }
    TraversalStep step;
    step.visitedNode = parentNodeIndex;
    step.visitedEdge = edge;
    return step;
}

