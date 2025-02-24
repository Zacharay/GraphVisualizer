#include <iostream>
#include "Application.hpp"
#include "Config.hpp"

int main() {
    Config::getInstance().load("config.json");
    Application app;
    app.run();
}
