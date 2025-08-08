#include "GraphParser.hpp"

void GraphParser::loadGraph(Graph &graph) {

    std::ifstream inputFile(m_inputFile);
    int V,E;

    inputFile >> V >> E;

    graph.resize(V);

    for (int i = 0; i < E; i++) {
        int u,v;
        inputFile >> u >> v;
        graph.addEdge(u,v,0,false);
    }
}
