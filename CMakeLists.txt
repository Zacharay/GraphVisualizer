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
)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/thirdParty)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)
# Link libraries
target_link_libraries(GraphVisualizer PRIVATE glfw ${OPENGL_LIBRARIES})

