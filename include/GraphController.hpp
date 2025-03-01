#pragma once
#include "GraphAlgorithm.hpp"
#include <memory>

class GraphController {
private:
    std::unique_ptr<GraphAlgorithm> algorithm;
public:
    void setAlgorithm(std::unique_ptr<GraphAlgorithm> algo) {
        algorithm = std::move(algo);
    }

    void start(int startNode) {
        if (algorithm) {
            algorithm->start(startNode);
        }
    }

    void update() {
        if (algorithm) algorithm->update();
    }
};