#pragma once
#include <GraphLayout.hpp>

#include "IMouseMode.hpp"
#include "../Graph.hpp"

class MoveNodesMode : public IMouseMode {
private:
    int m_selectedNode = -1;
    bool m_isDragging =false;
    GraphLayout &m_graphLayout;
public:
    MoveNodesMode(GraphLayout &layout) :m_graphLayout(layout){};
    void onMouseDown(int button, double x, double y) override;
    void onMouseUp(int button, double x, double y) override;
    void onMouseMove(double x, double y) override;
};