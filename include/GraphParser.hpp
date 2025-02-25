#pragma once
#include <string>

#include "Config.hpp"
#include "Graph.hpp"

enum ParsingMethod {
    STANDARD,
    STANDARD_WEIGHTED
};

class GraphParser{
public:
    const std::string m_inputFile = Config::getInstance().getInputFileName();
    ParsingMethod method = ParsingMethod::STANDARD;
    GraphParser()=default;
    void loadGraph(Graph& graph);
private:

};
