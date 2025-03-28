# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zachary/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/zachary/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zachary/cppProjects/GraphVisualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zachary/cppProjects/GraphVisualizer/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/GraphVisualizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GraphVisualizer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GraphVisualizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GraphVisualizer.dir/flags.make

CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/Application.cpp
CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/Application.cpp

CMakeFiles/GraphVisualizer.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/Application.cpp > CMakeFiles/GraphVisualizer.dir/src/Application.cpp.i

CMakeFiles/GraphVisualizer.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/Application.cpp -o CMakeFiles/GraphVisualizer.dir/src/Application.cpp.s

CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/DFSAlgorithm.cpp
CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/DFSAlgorithm.cpp

CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/DFSAlgorithm.cpp > CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.i

CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/DFSAlgorithm.cpp -o CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.s

CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/Graph.cpp
CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/Graph.cpp

CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/Graph.cpp > CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.i

CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/Graph.cpp -o CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.s

CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/GraphLayout.cpp
CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/GraphLayout.cpp

CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/GraphLayout.cpp > CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.i

CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/GraphLayout.cpp -o CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.s

CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/GraphParser.cpp
CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/GraphParser.cpp

CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/GraphParser.cpp > CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.i

CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/GraphParser.cpp -o CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.s

CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/GraphRenderer.cpp
CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/GraphRenderer.cpp

CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/GraphRenderer.cpp > CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.i

CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/GraphRenderer.cpp -o CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.s

CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/Renderer.cpp
CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/Renderer.cpp

CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/Renderer.cpp > CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.i

CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/Renderer.cpp -o CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.s

CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/Shader.cpp
CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/Shader.cpp

CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/Shader.cpp > CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.i

CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/Shader.cpp -o CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.s

CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/Window.cpp
CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/Window.cpp

CMakeFiles/GraphVisualizer.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/Window.cpp > CMakeFiles/GraphVisualizer.dir/src/Window.cpp.i

CMakeFiles/GraphVisualizer.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/Window.cpp -o CMakeFiles/GraphVisualizer.dir/src/Window.cpp.s

CMakeFiles/GraphVisualizer.dir/src/glad.c.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/glad.c.o: /home/zachary/cppProjects/GraphVisualizer/src/glad.c
CMakeFiles/GraphVisualizer.dir/src/glad.c.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/GraphVisualizer.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/glad.c.o -MF CMakeFiles/GraphVisualizer.dir/src/glad.c.o.d -o CMakeFiles/GraphVisualizer.dir/src/glad.c.o -c /home/zachary/cppProjects/GraphVisualizer/src/glad.c

CMakeFiles/GraphVisualizer.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GraphVisualizer.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/glad.c > CMakeFiles/GraphVisualizer.dir/src/glad.c.i

CMakeFiles/GraphVisualizer.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GraphVisualizer.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/glad.c -o CMakeFiles/GraphVisualizer.dir/src/glad.c.s

CMakeFiles/GraphVisualizer.dir/src/main.cpp.o: CMakeFiles/GraphVisualizer.dir/flags.make
CMakeFiles/GraphVisualizer.dir/src/main.cpp.o: /home/zachary/cppProjects/GraphVisualizer/src/main.cpp
CMakeFiles/GraphVisualizer.dir/src/main.cpp.o: CMakeFiles/GraphVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/GraphVisualizer.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphVisualizer.dir/src/main.cpp.o -MF CMakeFiles/GraphVisualizer.dir/src/main.cpp.o.d -o CMakeFiles/GraphVisualizer.dir/src/main.cpp.o -c /home/zachary/cppProjects/GraphVisualizer/src/main.cpp

CMakeFiles/GraphVisualizer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GraphVisualizer.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/cppProjects/GraphVisualizer/src/main.cpp > CMakeFiles/GraphVisualizer.dir/src/main.cpp.i

CMakeFiles/GraphVisualizer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GraphVisualizer.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/cppProjects/GraphVisualizer/src/main.cpp -o CMakeFiles/GraphVisualizer.dir/src/main.cpp.s

# Object files for target GraphVisualizer
GraphVisualizer_OBJECTS = \
"CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o" \
"CMakeFiles/GraphVisualizer.dir/src/glad.c.o" \
"CMakeFiles/GraphVisualizer.dir/src/main.cpp.o"

# External object files for target GraphVisualizer
GraphVisualizer_EXTERNAL_OBJECTS =

GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/Application.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/DFSAlgorithm.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/Graph.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/GraphLayout.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/GraphParser.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/GraphRenderer.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/Renderer.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/Shader.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/Window.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/glad.c.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/src/main.cpp.o
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/build.make
GraphVisualizer: /usr/lib64/libglfw.so.3.3
GraphVisualizer: /usr/lib64/libOpenGL.so
GraphVisualizer: /usr/lib64/libGLX.so
GraphVisualizer: /usr/lib64/libGLU.so
GraphVisualizer: CMakeFiles/GraphVisualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable GraphVisualizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphVisualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GraphVisualizer.dir/build: GraphVisualizer
.PHONY : CMakeFiles/GraphVisualizer.dir/build

CMakeFiles/GraphVisualizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GraphVisualizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GraphVisualizer.dir/clean

CMakeFiles/GraphVisualizer.dir/depend:
	cd /home/zachary/cppProjects/GraphVisualizer/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zachary/cppProjects/GraphVisualizer /home/zachary/cppProjects/GraphVisualizer /home/zachary/cppProjects/GraphVisualizer/cmake-build-release /home/zachary/cppProjects/GraphVisualizer/cmake-build-release /home/zachary/cppProjects/GraphVisualizer/cmake-build-release/CMakeFiles/GraphVisualizer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GraphVisualizer.dir/depend

