#pragma once
#include <stack>
#include <vector>
#include "GraphAlgorithm.hpp"
#include "core/Graph.hpp"
#include "layout/GraphLayout.hpp"

class DFSAlgorithm : public GraphAlgorithm {
private:

   std::stack<std::shared_ptr<Edge>>m_dfsStack;
   std::vector<bool> m_visited;
public:
   DFSAlgorithm(Graph& g, std::shared_ptr<GraphLayout> l) : GraphAlgorithm(g, l) {
      m_visited.resize(g.getSize());
   }

   void start(int startingNode)override;
   std::vector<std::shared_ptr<VisualizationEvent>> step()override;

};