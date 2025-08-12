#pragma once
#include "algorithms/GraphAlgorithm.hpp"
#include "layout/GraphLayout.hpp"
#include <memory>
#include "layout/GUI.hpp"
#include "core/AnimationController.hpp"

class GraphController {
private:
    std::unique_ptr<GraphAlgorithm> algorithm;
    std::shared_ptr<GraphLayout> m_layout;
    AnimationController m_animationController;

    bool m_isRunning=false;
public:
    GraphController(std::shared_ptr<GraphLayout> l) : m_layout(l) {}

    void setAlgorithm(std::unique_ptr<GraphAlgorithm> algo) {
        algorithm = std::move(algo);
    }

    void resetAlgorithm(std::unique_ptr<GraphAlgorithm> algo) {
        algorithm = std::move(algo);
        m_isRunning = false;
    }

    void start(int startNode) {
        if (algorithm && ! m_isRunning) {
            algorithm->start(startNode);
            m_isRunning = true;

        }
    }

    void update(float deltaTime,float visualizationSpeed,bool forceStep = false) {
        if (!algorithm || !algorithm->isRunning()) return;

        // For simplicity: call step every visualizationSpeed seconds
        static float timeAccumulator = visualizationSpeed;
        timeAccumulator += deltaTime;

        if (forceStep) {
            timeAccumulator = visualizationSpeed;
            m_animationController.update(timeAccumulator);
            auto newEvents = algorithm->step();
            for (auto &event : newEvents) {
                //low event startTime to forceStep without animating
                event->startTime = -1000;
                m_animationController.addEvent(event);
            }
            timeAccumulator = 0.0f;

            if (newEvents.empty()) {
                timeAccumulator = visualizationSpeed;
                update(deltaTime,visualizationSpeed,true);
            }
            return;
        }

        if (timeAccumulator >= visualizationSpeed) {
            auto newEvents = algorithm->step();
            for (auto &event : newEvents) {
                event->startTime = m_animationController.getTime();
                m_animationController.addEvent(event);
            }
            timeAccumulator = 0.0f;

            if (newEvents.empty()) {
                timeAccumulator = visualizationSpeed;
            }

        }

        m_animationController.update(deltaTime);
    }

    bool isRunning() const {
        if (!algorithm)return false;

        return algorithm->isRunning();
    }
    AnimationController& getAnimationController() { return m_animationController; }
};