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

# Include any dependencies generated for this target.
include test/CMakeFiles/load_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/load_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/load_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/load_test.dir/flags.make

test/CMakeFiles/load_test.dir/load_test/load_test.cpp.o: test/CMakeFiles/load_test.dir/flags.make
test/CMakeFiles/load_test.dir/load_test/load_test.cpp.o: /home/viacheslav/projects/labs_C++/lab1_release/test/load_test/load_test.cpp
test/CMakeFiles/load_test.dir/load_test/load_test.cpp.o: test/CMakeFiles/load_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/viacheslav/projects/labs_C++/lab1_release/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/load_test.dir/load_test/load_test.cpp.o"
	cd /home/viacheslav/projects/labs_C++/lab1_release/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/load_test.dir/load_test/load_test.cpp.o -MF CMakeFiles/load_test.dir/load_test/load_test.cpp.o.d -o CMakeFiles/load_test.dir/load_test/load_test.cpp.o -c /home/viacheslav/projects/labs_C++/lab1_release/test/load_test/load_test.cpp

test/CMakeFiles/load_test.dir/load_test/load_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/load_test.dir/load_test/load_test.cpp.i"
	cd /home/viacheslav/projects/labs_C++/lab1_release/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/viacheslav/projects/labs_C++/lab1_release/test/load_test/load_test.cpp > CMakeFiles/load_test.dir/load_test/load_test.cpp.i

test/CMakeFiles/load_test.dir/load_test/load_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/load_test.dir/load_test/load_test.cpp.s"
	cd /home/viacheslav/projects/labs_C++/lab1_release/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/viacheslav/projects/labs_C++/lab1_release/test/load_test/load_test.cpp -o CMakeFiles/load_test.dir/load_test/load_test.cpp.s

# Object files for target load_test
load_test_OBJECTS = \
"CMakeFiles/load_test.dir/load_test/load_test.cpp.o"

# External object files for target load_test
load_test_EXTERNAL_OBJECTS =

test/load_test: test/CMakeFiles/load_test.dir/load_test/load_test.cpp.o
test/load_test: test/CMakeFiles/load_test.dir/build.make
test/load_test: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.83.0
test/load_test: test/CMakeFiles/load_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/viacheslav/projects/labs_C++/lab1_release/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable load_test"
	cd /home/viacheslav/projects/labs_C++/lab1_release/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/load_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/load_test.dir/build: test/load_test
.PHONY : test/CMakeFiles/load_test.dir/build

test/CMakeFiles/load_test.dir/clean:
	cd /home/viacheslav/projects/labs_C++/lab1_release/build/test && $(CMAKE_COMMAND) -P CMakeFiles/load_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/load_test.dir/clean

test/CMakeFiles/load_test.dir/depend:
	cd /home/viacheslav/projects/labs_C++/lab1_release/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/viacheslav/projects/labs_C++/lab1_release /home/viacheslav/projects/labs_C++/lab1_release/test /home/viacheslav/projects/labs_C++/lab1_release/build /home/viacheslav/projects/labs_C++/lab1_release/build/test /home/viacheslav/projects/labs_C++/lab1_release/build/test/CMakeFiles/load_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/load_test.dir/depend

