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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/build

# Include any dependencies generated for this target.
include CMakeFiles/Visualization.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Visualization.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Visualization.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Visualization.dir/flags.make

CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o: CMakeFiles/Visualization.dir/flags.make
CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o: /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/src/PlotTraj.cpp
CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o: CMakeFiles/Visualization.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o -MF CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o.d -o CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o -c /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/src/PlotTraj.cpp

CMakeFiles/Visualization.dir/src/PlotTraj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Visualization.dir/src/PlotTraj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/src/PlotTraj.cpp > CMakeFiles/Visualization.dir/src/PlotTraj.cpp.i

CMakeFiles/Visualization.dir/src/PlotTraj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Visualization.dir/src/PlotTraj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/src/PlotTraj.cpp -o CMakeFiles/Visualization.dir/src/PlotTraj.cpp.s

# Object files for target Visualization
Visualization_OBJECTS = \
"CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o"

# External object files for target Visualization
Visualization_EXTERNAL_OBJECTS =

/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: CMakeFiles/Visualization.dir/src/PlotTraj.cpp.o
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: CMakeFiles/Visualization.dir/build.make
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_glgeometry.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_python.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_scene.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_tools.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_video.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_geometry.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libtinyobj.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_plot.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_display.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_vars.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_windowing.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_opengl.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/lib/x86_64-linux-gnu/libEGL.so
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/lib/x86_64-linux-gnu/libOpenGL.so
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/lib/x86_64-linux-gnu/libepoxy.so
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_image.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_packetstream.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: /usr/local/lib/libpango_core.so.0.9.2
/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so: CMakeFiles/Visualization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Visualization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Visualization.dir/build: /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/lib/libVisualization.so
.PHONY : CMakeFiles/Visualization.dir/build

CMakeFiles/Visualization.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Visualization.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Visualization.dir/clean

CMakeFiles/Visualization.dir/depend:
	cd /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/build /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/build /home/ctc/GitProjects/slambook2_CTC/Chapter04/02_traj_error/build/CMakeFiles/Visualization.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Visualization.dir/depend
