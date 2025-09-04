#include "algorithms/DijkstraAlgorithm.hpp"

#include <utils/json.hpp>

void DijkstraAlgorithm::start(int startingNode) {
    m_isRunning = true;

    m_distance.resize(m_graph.getSize());
    for (int i = 0; i < m_graph.getSize(); i++) {
        m_distance[i] = INT_MAX;
    }

    m_distance[startingNode] = 0;
    m_queue.push(std::make_shared<Edge>(startingNode,startingNode,0,true));
}
std::vector<std::shared_ptr<VisualizationEvent> > DijkstraAlgorithm::step() {
    std::vector<std::shared_ptr<VisualizationEvent>> events;

    if (m_queue.empty()) {
        m_isRunning = false;
        return events;
    }
    std::shared_ptr<Edge> currentEdge = m_queue.top();
    m_queue.pop();



    int nodeNumber = currentEdge->destination;
    m_layout->setNodeLabel(nodeNumber,std::to_string(m_distance[currentEdge->destination]));

    for (auto& e : m_graph.adjList[currentEdge->destination]) {
        if (m_distance[e->destination] > m_distance[currentEdge->destination] + e->weight) {
            m_distance[e->destination] = m_distance[currentEdge->destination] + e->weight;
            m_queue.push(e);
        }
    }


    return events;
}
