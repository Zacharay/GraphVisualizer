#pragma once
#include <layout/GraphLayout.hpp>

#include "IMouseMode.hpp"
#include "core/Graph.hpp"

class SpawnNodesMode : public IMouseMode {
private:
    Graph &m_graph;
    GraphLayout &m_graphLayout;
public:
    SpawnNodesMode(Graph &graph, GraphLayout &layout) : m_graph(graph),m_graphLayout(layout){};
    void onMouseDown(int button, double x, double y) override;
    void onMouseUp(int button, double x, double y) override {}
    void onMouseMove(double x, double y) override {}
};