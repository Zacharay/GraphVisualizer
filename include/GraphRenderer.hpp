#pragma once
#include <Renderer.hpp>

#include "Graph.hpp"

struct Node {
    unsigned int posX;
    unsigned int posY;
    glm::vec3 color;
    bool visited;
};
class GraphRenderer {
private:
    Graph m_graph;
    Renderer m_renderer;
    std::vector<Node>m_nodes;

    std::vector<int>m_dfsStack;
    std::vector<bool>m_visited;
    bool m_dfsIsRunning = false;
public:
    GraphRenderer(Graph& g,Renderer &r):m_graph(g),m_renderer(r) {
        m_nodes.resize(g.getSize());
    };
    void randomShuffleNodes();
    void nodesAtCircle(float circleRadius);
    void render();
    void startDfs(int startingNode);
    void updateDfs();
};