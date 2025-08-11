#pragma once
#include "../../thirdParty/glad/glad.h"
#include <GLFW/glfw3.h>

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

    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (win) {
            win->onMouseButton(button, action, mods);
        }
    };
    static void CursorPosCallback(GLFWwindow* window, double x, double y) {
        Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (win) {
            win->onCursorPosition(x,y);
        }
    }
    virtual void onMouseButton(int button,int action,int mods)=0;
    virtual void onCursorPosition(float x,float y)=0;
    virtual void onUpdate()=0;
    virtual void onRender()=0;

};