# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/viacheslav/projects/labs_C++/lab1_release

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/viacheslav/projects/labs_C++/lab1_release/build

# Utility rule file for ExperimentalMemCheck.

# Include any custom commands dependencies for this target.
include test/CMakeFiles/ExperimentalMemCheck.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/ExperimentalMemCheck.dir/progress.make

test/CMakeFiles/ExperimentalMemCheck:
	cd /home/viacheslav/projects/labs_C++/lab1_release/build/test && /usr/bin/ctest -D ExperimentalMemCheck

ExperimentalMemCheck: test/CMakeFiles/ExperimentalMemCheck
ExperimentalMemCheck: test/CMakeFiles/ExperimentalMemCheck.dir/build.make
.PHONY : ExperimentalMemCheck

# Rule to build all files generated by this target.
test/CMakeFiles/ExperimentalMemCheck.dir/build: ExperimentalMemCheck
.PHONY : test/CMakeFiles/ExperimentalMemCheck.dir/build

test/CMakeFiles/ExperimentalMemCheck.dir/clean:
	cd /home/viacheslav/projects/labs_C++/lab1_release/build/test && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalMemCheck.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/ExperimentalMemCheck.dir/clean

test/CMakeFiles/ExperimentalMemCheck.dir/depend:
	cd /home/viacheslav/projects/labs_C++/lab1_release/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viacheslav/projects/labs_C++/lab1_release /home/viacheslav/projects/labs_C++/lab1_release/test /home/viacheslav/projects/labs_C++/lab1_release/build /home/viacheslav/projects/labs_C++/lab1_release/build/test /home/viacheslav/projects/labs_C++/lab1_release/build/test/CMakeFiles/ExperimentalMemCheck.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/ExperimentalMemCheck.dir/depend
