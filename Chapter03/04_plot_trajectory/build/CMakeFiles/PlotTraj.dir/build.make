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
CMAKE_SOURCE_DIR = /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/build

# Include any dependencies generated for this target.
include CMakeFiles/PlotTraj.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PlotTraj.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PlotTraj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PlotTraj.dir/flags.make

CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o: CMakeFiles/PlotTraj.dir/flags.make
CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o: /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/src/Visualization.cpp
CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o: CMakeFiles/PlotTraj.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o -MF CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o.d -o CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o -c /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/src/Visualization.cpp

CMakeFiles/PlotTraj.dir/src/Visualization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PlotTraj.dir/src/Visualization.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/src/Visualization.cpp > CMakeFiles/PlotTraj.dir/src/Visualization.cpp.i

CMakeFiles/PlotTraj.dir/src/Visualization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PlotTraj.dir/src/Visualization.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/src/Visualization.cpp -o CMakeFiles/PlotTraj.dir/src/Visualization.cpp.s

# Object files for target PlotTraj
PlotTraj_OBJECTS = \
"CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o"

# External object files for target PlotTraj
PlotTraj_EXTERNAL_OBJECTS =

/home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/lib/libPlotTraj.a: CMakeFiles/PlotTraj.dir/src/Visualization.cpp.o
/home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/lib/libPlotTraj.a: CMakeFiles/PlotTraj.dir/build.make
/home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/lib/libPlotTraj.a: CMakeFiles/PlotTraj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/lib/libPlotTraj.a"
	$(CMAKE_COMMAND) -P CMakeFiles/PlotTraj.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PlotTraj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PlotTraj.dir/build: /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/lib/libPlotTraj.a
.PHONY : CMakeFiles/PlotTraj.dir/build

CMakeFiles/PlotTraj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PlotTraj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PlotTraj.dir/clean

CMakeFiles/PlotTraj.dir/depend:
	cd /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/build /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/build /home/ctc/GitProjects/slambook2_CTC/Chapter03/04_plot_trajectory/build/CMakeFiles/PlotTraj.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PlotTraj.dir/depend
