#pragma once
#include <Renderer.hpp>

#include "Graph.hpp"

struct Node {
    unsigned int posX;
    unsigned int posY;
    glm::vec3 color;

};
class GraphRenderer {
private:
    Graph m_graph;
    Renderer m_renderer;
    std::vector<Node>m_nodes;
public:
    GraphRenderer(Graph& g,Renderer &r):m_graph(g),m_renderer(r) {
        m_nodes.resize(g.getSize());
    };
    void randomShuffleNodes();
    void render();
};