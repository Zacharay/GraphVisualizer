#pragma once
#include <core/Graph.hpp>
#include <layout/GraphLayout.hpp>
#include <memory>
#include <optional>

#include "core/AnimationController.hpp"


struct TraversalStep {
    int visitedNode = -1;
    std::shared_ptr<Edge>visitedEdge = nullptr;
};

class GraphAlgorithm {
protected:
    Graph& m_graph;
    std::shared_ptr<GraphLayout> m_layout;
    bool m_isRunning = false;
public:
    GraphAlgorithm(Graph &g, std::shared_ptr<GraphLayout> l) : m_graph(g), m_layout(l) {}

    virtual void start(int startingNode)=0;
    virtual std::vector<std::shared_ptr<VisualizationEvent>> step () = 0;
    virtual ~GraphAlgorithm() = default;  // Virtual destructor

    bool isRunning() const { return m_isRunning; }
};
