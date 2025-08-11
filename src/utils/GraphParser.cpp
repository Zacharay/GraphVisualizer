#include "utils/GraphParser.hpp"

void GraphParser::loadGraph(Graph &graph) {

    std::ifstream inputFile(m_inputFile);
    int V,E;

    inputFile >> V >> E;

    graph.resize(V);

    for (int i = 0; i < E; i++) {

        if (m_parsingMethod == ParsingMethod::STANDARD) {
            int u,v;
            inputFile >> u >> v;
            graph.addEdge(u,v,0,true);
        }
        else if (m_parsingMethod == ParsingMethod::STANDARD_WEIGHTED) {
            int u,v,w;
            inputFile >> u >> v >> w;
            graph.addEdge(u,v,w,true);
        }


    }
}
