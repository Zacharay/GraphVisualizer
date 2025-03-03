#pragma once
#include <stack>
#include <vector>
#include "GraphAlgorithm.hpp"
#include "Graph.hpp"
#include "GraphLayout.hpp"

class DFSAlgorithm : public GraphAlgorithm {
private:
   bool m_isRunning = false;
   std::stack<std::shared_ptr<Edge>>m_dfsStack;
   std::vector<bool> m_visited;
public:
   DFSAlgorithm(Graph& g, std::shared_ptr<GraphLayout> l) : GraphAlgorithm(g, l) {
      m_visited.resize(g.getSize());
   }

   void start(int startingNode)override;
   void update()override;

};