#pragma once
#include "IMouseMode.hpp"
#include "SpawnNodesMode.hpp"
#include "MoveNodesMode.hpp"

enum MouseModeType {
    SPAWN_NODES,
    MOVE_NODES
};
constexpr const char * MouseModeNames[] = {
    "Spawn Nodes",
    "Move Nodes"
};

class MouseModeFactory {
public:
    static std::unique_ptr<IMouseMode> create(MouseModeType type, Graph& graph, GraphLayout& layout) {
        switch (type) {
            case MouseModeType::SPAWN_NODES:
                return std::make_unique<SpawnNodesMode>(graph, layout);
            case MouseModeType::MOVE_NODES:
                return std::make_unique<MoveNodesMode>(layout);
                    break;
            default:
                return nullptr;
        }
    }
};

