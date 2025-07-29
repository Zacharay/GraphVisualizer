#pragma once
#include <Graph.hpp>
#include <GraphLayout.hpp>
#include <memory>
#include <optional>


struct TraversalStep {
    int visitedNode = -1;
    std::shared_ptr<Edge>visitedEdge = nullptr;
};

class GraphAlgorithm {
protected:
    Graph& m_graph;
    std::shared_ptr<GraphLayout> m_layout;
public:
    GraphAlgorithm(Graph &g, std::shared_ptr<GraphLayout> l) : m_graph(g), m_layout(l) {}

    virtual void start(int startingNode)=0;
    virtual std::optional<TraversalStep> step () = 0;
    virtual ~GraphAlgorithm() = default;  // Virtual destructor
};
