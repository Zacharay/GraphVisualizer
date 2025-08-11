#pragma once
#include <string>

#include "utils/Config.hpp"
#include "core/Graph.hpp"

enum ParsingMethod {
    STANDARD,
    STANDARD_WEIGHTED
};

class GraphParser{
public:
    const std::string m_inputFile = Config::getInstance().getInputFileName();
    ParsingMethod m_parsingMethod = ParsingMethod::STANDARD_WEIGHTED;
    GraphParser()=default;
    void loadGraph(Graph& graph);
private:

};
