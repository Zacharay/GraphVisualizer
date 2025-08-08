#include "GraphRenderer.hpp"
#include "Config.hpp"


void GraphRenderer::render(const float animationSpeed)  {
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

                progress = timeSinceActivated / animationSpeed;
                if (progress > 1.0f) progress = 1.0f;
            }

            const float nodeRadius = Config::getInstance().getNodeRadius();

            glm::vec2 from(nodeFrom.posX, nodeFrom.posY);
            glm::vec2 to(nodeTo.posX, nodeTo.posY);

            // Direction vector
            glm::vec2 dir = to - from;
            float distance = glm::length(dir);
            if (distance > 1e-5f) {
                dir /= distance; // normalize

                glm::vec2 newFrom = from + dir * nodeRadius;
                glm::vec2 newTo = to - dir * nodeRadius;


                if (!edge->isBidirectional) {
                    m_renderer.drawAnimatedEdge(
                    glm::vec3(newFrom, 1.0f),
                    glm::vec3(newTo - 16.0f * dir, 1.0f),
                    progress);

                    // Draw static arrowhead at the end of the edge
                    glm::vec3 arrowColor = edge->isActivated()
                        ? glm::vec3(1.0f, 0.3f, 0.3f) // Red for active
                        : glm::vec3(0.3f, 0.3f, 1.0f); // Gray for inactive

                    m_renderer.drawArrowhead(
                        glm::vec3(newFrom, 1.0f),
                        glm::vec3(newTo, 1.0f),
                        arrowColor
                    );
                }
                else {
                    m_renderer.drawAnimatedEdge(
                    glm::vec3(newFrom, 1.0f),
                    glm::vec3(newTo, 1.0f),
                    progress);

                }

            } else {
                // Nodes are on top of each other — avoid division by zero
                m_renderer.drawAnimatedEdge(
                    glm::vec3(from, 1.0f),
                    glm::vec3(to, 1.0f),
                    progress);
            }



        }
    }

}
