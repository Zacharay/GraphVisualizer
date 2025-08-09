cmake_minimum_required(VERSION 3.10)
project(GraphVisualizer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set policy for OpenGL preference
if(POLICY CMP0072)
        cmake_policy(SET CMP0072 NEW)
endif()

# Find packages
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/thirdParty/imgui)
list(APPEND SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/imgui_impl_opengl3.cpp
)

# Add the executable
add_executable(GraphVisualizer ${SOURCES}
        src/Window.cpp
        src/main.cpp
        include/Window.hpp
        include/Application.hpp
        src/Shader.cpp
        include/GraphRenderer.hpp
        include/Config.hpp
        include/GraphParser.hpp
        include/GUI.hpp
        src/GUI.cpp
        include/BFSAlgorithm.hpp
        src/BFSAlgorithm.cpp
        include/input/MouseModeFactory.hpp
        include/input/IMouseMode.hpp
        include/input/SpawnNodesMode.hpp
        src/input/SpawnNodesMode.cpp
        include/input/MoveNodesMode.hpp
        src/input/MoveNodesMode.cpp
        include/input/AddEdgesMode.hpp
        src/input/AddEdgesMode.cpp
        src/TextRenderer.cpp
        include/TextRenderer.hpp
        src/stb_image.cpp
)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/thirdParty)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)
# Link libraries
target_link_libraries(GraphVisualizer PRIVATE
        glfw
        ${OPENGL_LIBRARIES}
        )

