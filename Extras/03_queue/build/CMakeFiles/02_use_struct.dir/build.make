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
CMAKE_SOURCE_DIR = /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/build

# Include any dependencies generated for this target.
include CMakeFiles/02_use_struct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/02_use_struct.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/02_use_struct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/02_use_struct.dir/flags.make

CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o: CMakeFiles/02_use_struct.dir/flags.make
CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o: /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/examples/02_use_struct.cpp
CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o: CMakeFiles/02_use_struct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o -MF CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o.d -o CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o -c /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/examples/02_use_struct.cpp

CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/examples/02_use_struct.cpp > CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.i

CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/examples/02_use_struct.cpp -o CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.s

# Object files for target 02_use_struct
02_use_struct_OBJECTS = \
"CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o"

# External object files for target 02_use_struct
02_use_struct_EXTERNAL_OBJECTS =

/home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/bin/02_use_struct: CMakeFiles/02_use_struct.dir/examples/02_use_struct.cpp.o
/home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/bin/02_use_struct: CMakeFiles/02_use_struct.dir/build.make
/home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/bin/02_use_struct: CMakeFiles/02_use_struct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/bin/02_use_struct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/02_use_struct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/02_use_struct.dir/build: /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/bin/02_use_struct
.PHONY : CMakeFiles/02_use_struct.dir/build

CMakeFiles/02_use_struct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/02_use_struct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/02_use_struct.dir/clean

CMakeFiles/02_use_struct.dir/depend:
	cd /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/build /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/build /home/ctc/GitProjects/slambook2_CTC/Extras/03_queue/build/CMakeFiles/02_use_struct.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/02_use_struct.dir/depend

