#pragma once
#include "GraphAlgorithm.hpp"
#include "layout/GraphLayout.hpp"
#include <queue>


class BFSAlgorithm : public GraphAlgorithm {
private:

    std::queue<std::shared_ptr<Edge>>m_queue;
    std::vector<bool> m_visited;
public:
    BFSAlgorithm(Graph& g, std::shared_ptr<GraphLayout> l) : GraphAlgorithm(g, l) {
        m_visited.resize(g.getSize());
    }

    void start(int startingNode)override;
    std::vector<std::shared_ptr<VisualizationEvent>> step()override;


};