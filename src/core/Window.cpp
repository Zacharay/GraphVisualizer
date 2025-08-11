#include "../../include/core/Window.hpp"
#include <iostream>

#include "../../include/utils/Config.hpp"


#include "../../thirdParty/imgui/imgui.h"
#include "../../thirdParty/imgui/imgui_impl_glfw.h"
#include "../../thirdParty/imgui/imgui_impl_opengl3.h"
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
    glfwWindowHint(GLFW_SAMPLES, 8);

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
    glfwSetCursorPosCallback(m_window,CursorPosCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glViewport(0, 0, windowWidth, windowHeight);
    glEnable(GL_MULTISAMPLE);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330");


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

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();



        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f,0.0f,0.0f,1.0f);


        onUpdate();


        onRender();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        calculateFps();

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
