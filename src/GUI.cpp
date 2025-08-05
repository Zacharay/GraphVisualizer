#include "GUI.hpp"
#include "Config.hpp"

void GUI::renderGUI() {
    const float sideBarWidth = 300.0f;
    // Ustaw pozycję i rozmiar okna ImGui - po prawej stronie, na całej wysokości
    ImGui::SetNextWindowPos(ImVec2(Config::getInstance().getWindowWidth()-sideBarWidth, 0));
    ImGui::SetNextWindowSize(ImVec2(sideBarWidth, (float)Config::getInstance().getWindowHeight()));
    // Example window
    ImGui::Begin("TopBar", nullptr,
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoSavedSettings);


        const char* algorithm_items[] = { "DFS", "BFS"};
        ImGui::Combo("Algorithm", &m_selectedAlgorithm, algorithm_items, IM_ARRAYSIZE(algorithm_items));

        static int start_node = 0;
        ImGui::InputInt("Start Node", &start_node);

        ImGui::Separator();

        if (ImGui::Button("Run")) {
            m_settings.state = AlgorithmState::RUNNING;
        }
        ImGui::SameLine();
        if (ImGui::Button("Pause")) {
            m_settings.state = AlgorithmState::IDLE;
        }
        ImGui::SameLine();
        if (ImGui::Button("Step")) {
           m_settings.state = AlgorithmState::STEP;
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset")) {
            m_settings.state = AlgorithmState::RESET;
        }

        ImGui::Separator();

        static float speed = 1.0f;
        ImGui::SliderFloat("Speed", &speed, 0.1f, 5.0f, "%.1f×");

        ImGui::Checkbox("Highlight visited nodes", &m_settings.highlightVisited);
        ImGui::Checkbox("Show traversal order", &m_settings.showTraversalOrder);
        ImGui::Checkbox("Mark activated edges", &m_settings.markActivatedEdges);


    ImGui::End();

    // Rendering
    ImGui::Render();
}
