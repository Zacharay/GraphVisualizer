#include "GUI.hpp"
#include "Config.hpp"

void GUI::renderGUI(int maxNode) {
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

        ImGui::SliderInt("Start Node", &m_startingNode, 0, maxNode);

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


        ImGui::SliderFloat("Step Delay", &m_settings.visualizationSpeed, 0.5f, 2.0f, "%.1fs");


    ImGui::End();

    // Rendering
    ImGui::Render();
}
