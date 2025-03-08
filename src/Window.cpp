#include "Window.hpp"
#include <iostream>

#include "Config.hpp"

// Constructor
Window::Window()
: frameCount(0),previousTime(glfwGetTime()),m_window(nullptr)
{

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(-1);
    }
    const unsigned int windowWidth = Config::getInstance().getWindowWidth();
    const unsigned int windowHeight = Config::getInstance().getWindowHeight();

    m_window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL Window", nullptr, nullptr);
    if (!m_window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }


    glfwMakeContextCurrent(m_window);

    // Store pointer to this instance in user data
    glfwSetWindowUserPointer(m_window, this);

    // Set the mouse button callback
    glfwSetMouseButtonCallback(m_window, MouseButtonCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glViewport(0, 0, windowWidth, windowHeight);

}

// Destructor
Window::~Window() {
    if (m_window) {
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
}

void Window::calculateFps() {
    double currentTime = glfwGetTime();
    double elapsedTime = currentTime - previousTime;
    frameCount++;

    if (elapsedTime >= 1.0) { // If a second has passed
        double fps = static_cast<double>(frameCount) / elapsedTime;

        if(Config::getInstance().isShowingFps()) {
            std::cout << fps << std::endl;
        }

        // Reset for the next calculation
        previousTime = currentTime;
        frameCount = 0;
    }
}
void Window::run()  {
    glEnable(GL_DEPTH_TEST);
    glfwSwapInterval(0);
    while (!glfwWindowShouldClose(m_window)) {

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);


        onUpdate();

        onRender();

        calculateFps();

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}
