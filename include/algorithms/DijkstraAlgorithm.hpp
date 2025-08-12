#pragma once
#include <queue>

#include "GraphAlgorithm.hpp"

class DijkstraAlgorithm : public GraphAlgorithm {
private:
    std::priority_queue<std::shared_ptr<Edge>> m_queue;
    std::vector<int> m_distance;
    int startNode,endNode;
public:
    DijkstraAlgorithm(Graph& g, std::shared_ptr<GraphLayout> l ,int startNode, int endNode): GraphAlgorithm(g, l),startNode(startNode),endNode(endNode){}
    void start(int startingNode) override;
    std::vector<std::shared_ptr<VisualizationEvent>> step() override;
};