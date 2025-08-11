#include <iostream>
#include "core/Application.hpp"
#include "../include/utils/Config.hpp"

int main() {
    Config::getInstance().load("config.json");
    Application app;
    app.run();
}
