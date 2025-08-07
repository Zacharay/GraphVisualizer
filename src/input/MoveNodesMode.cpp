#include "input/MoveNodesMode.hpp"


void MoveNodesMode::onMouseDown(int button, double x, double y) {
    m_selectedNode = m_graphLayout.getNodeIdxByCoordinates(x,y);
    m_isDragging = true;
}
void MoveNodesMode::onMouseUp(int button, double x, double y) {
    m_selectedNode = -1;
    m_isDragging = false;
}
void MoveNodesMode::onMouseMove(double x, double y) {
    if (m_selectedNode != -1 && m_isDragging) {
        m_graphLayout.setNodePosition(m_selectedNode,x,y);
    }
}
