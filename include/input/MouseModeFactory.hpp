#pragma once
#include "AddEdgesMode.hpp"
#include "IMouseMode.hpp"
#include "SpawnNodesMode.hpp"
#include "MoveNodesMode.hpp"

enum MouseModeType {
    SPAWN_NODES,
    MOVE_NODES,
    ADD_EDGES
};
constexpr const char * MouseModeNames[] = {
    "Spawn Nodes",
    "Move Nodes",
    "Add Edges"
};

class MouseModeFactory {
public:
    static std::unique_ptr<IMouseMode> create(MouseModeType type, Graph& graph, GraphLayout& layout) {
        switch (type) {
            case MouseModeType::SPAWN_NODES:
                return std::make_unique<SpawnNodesMode>(graph, layout);
            case MouseModeType::MOVE_NODES:
                return std::make_unique<MoveNodesMode>(layout);
            case MouseModeType::ADD_EDGES:
                return std::make_unique<AddEdgesMode>(graph,layout);
            default:
                return nullptr;
        }
    }
};

