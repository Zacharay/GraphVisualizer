#pragma once
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

class Config {
public:
    static Config& getInstance() {
        static Config instance;
        return instance;
    }
    void load(const std::string& filename) {
        std::ifstream configFile(filename);
        if (!configFile) {
            std::cerr << "Failed to open config file: " << filename << std::endl;
            return;
        }
        configFile >> m_configData;
    }
    float getNodeRadius()const{return m_configData["visualization"]["nodeRadius"];}
    float getSideBarWidth()const{return sideBarWidth;}
    unsigned int getWindowWidth()const{return m_configData["window"]["width"];}
    unsigned int getWindowHeight()const{return m_configData["window"]["height"];}
    bool isShowingFps()const{return m_configData["logging"]["showFps"];}
    std::string getInputFileName(){return m_configData["parser"]["inputFileName"];};
private:
    const float sideBarWidth = 300.0f;
    float m_nodeRadius;
    json m_configData;
    Config()=default;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
};