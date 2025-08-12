#include "render/GraphRenderer.hpp"
#include "../include/utils/Config.hpp"
#include "core/AnimationController.hpp"


void GraphRenderer::render(std::vector<std::shared_ptr<VisualizationEvent>>& events,float animationSpeed,float time)  {
    // Reset flags
    for (auto& edgesFrom : m_layout->getEdges()) {
        for (auto& edge : edgesFrom) {
            edge->skipDraw = false;
        }
    }

    for (auto &event : events) {
        event->apply(*m_layout);
    }

    drawNodes();
    drawEdges(animationSpeed);


    for (auto & event : events) {
        event->render(*this,*m_layout,time,animationSpeed);
    }
}
void GraphRenderer::drawNodes() {
    for(const Node &node:m_layout->getNodes()) {
        m_renderer.drawNode(node.posX,node.posY,node.color);
    }
}
void GraphRenderer::drawEdges(float animationSpeed) {
    const auto &edges = m_layout->getEdges();

    for (int from = 0; from < edges.size(); from++) {
        for (const auto &edge : edges[from]) {
            if (edge->skipDraw) continue;

            if (edge->twin) {
                edge->twin->skipDraw=true;
            }

            const Node &nodeFrom = m_layout->getNodes()[from];
            const Node &nodeTo = m_layout->getNodes()[edge->destination];

            const float progress = 0.0f;

            glm::vec2 fromPos(nodeFrom.posX, nodeFrom.posY);
            glm::vec2 toPos(nodeTo.posX, nodeTo.posY);



            drawEdge(fromPos,toPos,edge, progress);

        }
    }
}
void GraphRenderer::drawEdge(const glm::vec2 &from, const glm::vec2 &to,
                             const std::shared_ptr<Edge> &edge, float progress) {

    const float nodeRadius = Config::getInstance().getNodeRadius();
    glm::vec2 dir = to - from;
    float dist = glm::length(dir);

    if (dist < 1e-5f) {
        // Nodes coincide, just draw edge directly
        m_renderer.drawAnimatedEdge(glm::vec3(from, 1.0f), glm::vec3(to, 1.0f), progress);
        return;
    }

    dir /= dist; // normalize direction
    glm::vec2 startPos = from + dir * nodeRadius;
    glm::vec2 endPos = to - dir * nodeRadius;

    if (!edge->isBidirectional) {
        m_renderer.drawAnimatedEdge(glm::vec3(startPos, 1.0f), glm::vec3(endPos - 16.0f * dir, 1.0f), progress);

        glm::vec3 arrowColor = glm::vec3(0.3f, 0.3f, 1.0f); // inactive blue

        m_renderer.drawArrowhead(glm::vec3(startPos, 1.0f), glm::vec3(endPos, 1.0f), arrowColor);
    } else {
        m_renderer.drawAnimatedEdge(glm::vec3(startPos, 1.0f), glm::vec3(endPos, 1.0f), progress);
    }

    if (edge->weight != -1) {
        std::string edgeWeight = std::to_string(edge->weight);
        drawEdgeWeight(from,to,edgeWeight);
    }
}

void GraphRenderer::drawEdgeWeight(const glm::vec2 &edgeFrom,const glm::vec2 &edgeTo,const std::string &weight) {
    // 2. Prepare for text rendering
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glm::vec2 edgeDir = edgeTo - edgeFrom;

    float length = glm::length(edgeDir);
    if (length > 1e-5f) {
        glm::vec2 edgeDirNorm = edgeDir / length;
        glm::vec2 perp(-edgeDirNorm.y, edgeDirNorm.x);

        const float offsetAmount = 5.0f;

        glm::vec2 labelPos = (edgeFrom + edgeTo) * 0.5f + perp * offsetAmount ;
        //TODO CENTER WEIGHT TEXT
        m_textRenderer.DrawText(weight, labelPos.x, Config::getInstance().getWindowHeight() - labelPos.y);
    } else {
        glm::vec2 labelPos = (edgeFrom + edgeTo) * 0.5f;
        m_textRenderer.DrawText(weight, labelPos.x, labelPos.y);
    }
    glEnable(GL_DEPTH_TEST);
}



