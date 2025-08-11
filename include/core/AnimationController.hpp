#pragma once
#include <vector>
#include <core/Graph.hpp>
#include "animations/VisualizationEvent.hpp"


class AnimationController {
    std::vector<std::shared_ptr<VisualizationEvent>> m_events;
    float m_time = 0.0f;
public:
    void resetEvents() {
        m_events.clear();
    }
    void addEvent(std::shared_ptr<VisualizationEvent>e) { m_events.push_back(e); }
    void update(float dt) {
        m_time += dt;
    }
    std::vector<std::shared_ptr<VisualizationEvent>> getActiveEvents()  {
        std::vector<std::shared_ptr<VisualizationEvent>> active;
        for (auto& e : m_events) {
            if (m_time >= e->startTime) active.push_back(e);
        }
        return active;
    }

    float getTime() const { return m_time; }
};