#include "Graph.hpp"
#include <iostream>
Graph::Graph(int graphSize){
    adjList.resize(graphSize);
    adjList.reserve(graphSize);
}
void Graph::addEdge(int from,int to,int weight,bool isBidirectional){

    std::shared_ptr<Edge> edge = std::make_shared<Edge>(to, weight, isBidirectional);
    adjList[from].push_back(edge);

    if (isBidirectional) {
        std::shared_ptr<Edge> twinEdge = std::make_shared<Edge>(from, weight, isBidirectional);
        adjList[to].push_back(twinEdge);
        // Assign twin pointers after both edges exist
        edge->twin = twinEdge;
        twinEdge->twin = edge;
    }

}
void Graph::resize(int numberOfNodes) {
    adjList.resize(numberOfNodes);
    adjList.reserve(numberOfNodes);
}
void Graph::printGraph()const{

    for(int i=1;i<adjList.size();i++){
        std::cout<<i<<"  ";
        for(int j=0;j<adjList[i].size();j++){
            std::cout<<adjList[i][j]->destination<<"("<<adjList[i][j]->weight<<")"<<" ";

        }
        std::cout<<std::endl;
    }
}
unsigned int Graph::getSize()const {
    return adjList.size();
}
