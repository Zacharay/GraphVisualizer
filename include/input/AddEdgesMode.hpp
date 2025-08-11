#pragma once
#include <core/Graph.hpp>
#include "layout/GraphLayout.hpp"

#include "IMouseMode.hpp"

class AddEdgesMode : public IMouseMode {
private:
    int m_selectedNode = -1;

    GraphLayout &m_graphLayout;
    Graph &m_graph;
public:
    AddEdgesMode(Graph &graph, GraphLayout &layout) :m_graph(graph),m_graphLayout(layout){};
    void onMouseDown(int button, double x, double y) override;
    void onMouseUp(int button, double x, double y) override{};
    void onMouseMove(double x, double y) override{};
};