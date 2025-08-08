#include "input/AddEdgesMode.hpp"

void AddEdgesMode::onMouseDown(int button, double x, double y) {
    if (m_selectedNode == -1) {

        m_selectedNode = m_graphLayout.getNodeIdxByCoordinates(x,y);
    }
    else {
        int temp = m_graphLayout.getNodeIdxByCoordinates(x,y);

        if (temp!= -1 && temp != m_selectedNode) {
            m_graph.addEdge(temp, m_selectedNode,0,true);
            m_selectedNode = -1;
        }
    }
}
