# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching

# Include any dependencies generated for this target.
include CMakeFiles/Terrain-Sketching.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Terrain-Sketching.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Terrain-Sketching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Terrain-Sketching.dir/flags.make

CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/main.cpp

CMakeFiles/Terrain-Sketching.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/main.cpp > CMakeFiles/Terrain-Sketching.dir/src/main.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/main.cpp -o CMakeFiles/Terrain-Sketching.dir/src/main.cpp.s

CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o: src/utils/utils.cpp
CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/utils/utils.cpp

CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/utils/utils.cpp > CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/utils/utils.cpp -o CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.s

CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o: src/terrain/terrain.cpp
CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/terrain/terrain.cpp

CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/terrain/terrain.cpp > CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/terrain/terrain.cpp -o CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.s

CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o: src/camera/camera.cpp
CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/camera/camera.cpp

CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/camera/camera.cpp > CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/camera/camera.cpp -o CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.s

CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o: src/stroke/stroke.cpp
CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/stroke.cpp

CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/stroke.cpp > CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/stroke.cpp -o CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.s

CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o: src/stroke/sillhouette/sillhouette.cpp
CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/sillhouette/sillhouette.cpp

CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/sillhouette/sillhouette.cpp > CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/sillhouette/sillhouette.cpp -o CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.s

CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o: src/stroke/shadow/shadow.cpp
CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/shadow/shadow.cpp

CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/shadow/shadow.cpp > CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/shadow/shadow.cpp -o CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.s

CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o: src/stroke/boundary/boundary.cpp
CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/boundary/boundary.cpp

CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/boundary/boundary.cpp > CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.i

CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/boundary/boundary.cpp -o CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.s

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o: depends/imgui/imgui_impl_glfw.cpp
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_impl_glfw.cpp

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_impl_glfw.cpp > CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_impl_glfw.cpp -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o: depends/imgui/imgui_impl_opengl3.cpp
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_impl_opengl3.cpp

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_impl_opengl3.cpp > CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.s

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o: depends/imgui/imgui.cpp
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui.cpp

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui.cpp > CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.i

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui.cpp -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.s

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o: depends/imgui/imgui_demo.cpp
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_demo.cpp

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_demo.cpp > CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.i

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_demo.cpp -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.s

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o: depends/imgui/imgui_draw.cpp
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_draw.cpp

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_draw.cpp > CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.i

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_draw.cpp -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.s

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o: CMakeFiles/Terrain-Sketching.dir/flags.make
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o: depends/imgui/imgui_widgets.cpp
CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o: CMakeFiles/Terrain-Sketching.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o -MF CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o -c /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_widgets.cpp

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_widgets.cpp > CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.i

CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/depends/imgui/imgui_widgets.cpp -o CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.s

# Object files for target Terrain-Sketching
Terrain__Sketching_OBJECTS = \
"CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o" \
"CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o"

# External object files for target Terrain-Sketching
Terrain__Sketching_EXTERNAL_OBJECTS =

bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/main.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/utils/utils.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/terrain/terrain.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/camera/camera.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/stroke/stroke.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/stroke/sillhouette/sillhouette.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/stroke/shadow/shadow.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/src/stroke/boundary/boundary.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_glfw.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_impl_opengl3.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_demo.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_draw.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/depends/imgui/imgui_widgets.cpp.o
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/build.make
bin/Terrain-Sketching: /usr/local/lib/libglfw.3.3.dylib
bin/Terrain-Sketching: /usr/local/lib/libGLEW.dylib
bin/Terrain-Sketching: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.0.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
bin/Terrain-Sketching: CMakeFiles/Terrain-Sketching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable bin/Terrain-Sketching"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Terrain-Sketching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Terrain-Sketching.dir/build: bin/Terrain-Sketching
.PHONY : CMakeFiles/Terrain-Sketching.dir/build

CMakeFiles/Terrain-Sketching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Terrain-Sketching.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Terrain-Sketching.dir/clean

CMakeFiles/Terrain-Sketching.dir/depend:
	cd /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching /Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/CMakeFiles/Terrain-Sketching.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Terrain-Sketching.dir/depend
