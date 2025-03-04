#include "GraphRenderer.hpp"

#include <iostream>
#include <ostream>
#include <random>

#include "Config.hpp"
#include "Window.hpp"

bool x = false;

void GraphRenderer::render()  {
    for(const Node &node:m_layout->getNodes()) {
        m_renderer.drawNode(node.posX,node.posY,node.color);
    }
    const std::vector<std::vector<std::shared_ptr<Edge>>> edges = m_layout->getEdges();

    for(int from=0;from<edges.size();from++) {
        for(std::shared_ptr<Edge> edge: edges[from]) {
            const Node &nodeFrom = m_layout->getNodes()[from];
            const Node &nodeTo = m_layout->getNodes()[edge->destination];

            float progress =0.0f;
            if(edge->activationTime != -1) {

                float timeSinceActivated = glfwGetTime()- edge->activationTime;
                //if(timeSinceActivated<1.0f)
                //std::cout << "Edge to "<<edge->destination<<" time since activated "<<timeSinceActivated<<" activation time "<<edge->activationTime<<std::endl;
                progress = fminf(timeSinceActivated/5.0f,1.0f);



            }
            m_renderer.drawAnimatedEdge(
                               glm::vec3(nodeFrom.posX,nodeFrom.posY,1.0f),
                               glm::vec3(nodeTo.posX,nodeTo.posY,1.0f),
                               edge->color,
                               progress);

        }
    }

}
