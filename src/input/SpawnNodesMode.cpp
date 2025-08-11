#include "input/SpawnNodesMode.hpp"

#include "../../include/utils/Config.hpp"

void SpawnNodesMode::onMouseDown(int button, double x, double y) {

    if (x >=0 && y >= 0 && x<= Config::getInstance().getWindowWidth() - Config::getInstance().getSideBarWidth() && y <= Config::getInstance().getWindowHeight()) {
        m_graph.addNewNode();
        m_graphLayout.addNewNode(x,y);
    }


}
