#include "GraphRenderer.hpp"
#include "Config.hpp"


void GraphRenderer::render()  {
    for(const Node &node:m_layout->getNodes()) {
        m_renderer.drawNode(node.posX,node.posY,node.color);
    }
    const std::vector<std::vector<std::shared_ptr<Edge>>> edges = m_layout->getEdges();

    for(int from=0;from<edges.size();from++) {
        for(std::shared_ptr<Edge> edge: edges[from]) {

            //preventing edges from overlaping 
            if (edge->twin && edge->twin->isActivated()) {
                continue;
            }

            const Node &nodeFrom = m_layout->getNodes()[from];
            const Node &nodeTo = m_layout->getNodes()[edge->destination];

            float progress = 0.0f;
            // Check if activationTime is valid
            if (edge->isActivated()) {
                // Calculate time since activation in seconds
                auto now = std::chrono::high_resolution_clock::now();
                auto timeSinceActivated = std::chrono::duration<float>(now - edge->activation_time).count();

                // Calculate progress (capped at 1.0f)
                progress = timeSinceActivated>1.0f?1.0f:timeSinceActivated;
            }
            m_renderer.drawAnimatedEdge(
                               glm::vec3(nodeFrom.posX,nodeFrom.posY,1.0f),
                               glm::vec3(nodeTo.posX,nodeTo.posY,1.0f),
                               progress);

        }
    }

}
