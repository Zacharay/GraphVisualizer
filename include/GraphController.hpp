#pragma once
#include "GraphAlgorithm.hpp"
#include <memory>

class GraphController {
private:
    std::unique_ptr<GraphAlgorithm> algorithm;
    std::shared_ptr<GraphLayout> m_layout;
    bool m_isRunning=false;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_lastUpdateTimeStamp{};
public:
    GraphController(std::shared_ptr<GraphLayout> l) : m_layout(l) {}

    void setAlgorithm(std::unique_ptr<GraphAlgorithm> algo) {
        algorithm = std::move(algo);
    }

    void start(int startNode) {
        if (algorithm && ! m_isRunning) {
            algorithm->start(startNode);
            m_isRunning = true;

        }
    }

    void update() {
        if (!algorithm || !m_isRunning)return;

        if (m_lastUpdateTimeStamp == std::chrono::time_point<std::chrono::high_resolution_clock>::min()) {
            m_lastUpdateTimeStamp = std::chrono::high_resolution_clock::now();
        }

        std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();

        auto elapsed=std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_lastUpdateTimeStamp).count();

        if (elapsed > 1000) {
            auto step = algorithm->step();
            if (step) {
                if (step->visitedNode != -1)
                    m_layout->setNodeColor(step->visitedNode, glm::vec3(1.0f,0.0f,0.0f));

                if (step->visitedEdge) {
                    step->visitedEdge->activation_time = std::chrono::high_resolution_clock::now();
                }
                m_lastUpdateTimeStamp = std::chrono::high_resolution_clock::now();
            }


        }
    }

    bool isRunning() const {
        return m_isRunning;
    }
};