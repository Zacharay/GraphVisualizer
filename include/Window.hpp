#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 1000;

class Window  {
private:
    void calculateFps();
    int frameCount;
    double previousTime;
public:
    Window();
    void run();
protected:
    GLFWwindow *m_window;
    ~Window();


    virtual void onUpdate()=0;
    virtual void onRender()=0;

};