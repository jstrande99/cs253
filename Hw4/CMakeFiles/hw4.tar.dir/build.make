# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /s/bach/j/under/jstrande/cs253/Hw4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/bach/j/under/jstrande/cs253/Hw4

# Utility rule file for hw4.tar.

# Include the progress variables for this target.
include CMakeFiles/hw4.tar.dir/progress.make

CMakeFiles/hw4.tar:
	tar cf hw4.tar Ratio.cc Ratio.h test.cc CMakeLists.txt

hw4.tar: CMakeFiles/hw4.tar
hw4.tar: CMakeFiles/hw4.tar.dir/build.make

.PHONY : hw4.tar

# Rule to build all files generated by this target.
CMakeFiles/hw4.tar.dir/build: hw4.tar

.PHONY : CMakeFiles/hw4.tar.dir/build

CMakeFiles/hw4.tar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw4.tar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw4.tar.dir/clean

CMakeFiles/hw4.tar.dir/depend:
	cd /s/bach/j/under/jstrande/cs253/Hw4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/bach/j/under/jstrande/cs253/Hw4 /s/bach/j/under/jstrande/cs253/Hw4 /s/bach/j/under/jstrande/cs253/Hw4 /s/bach/j/under/jstrande/cs253/Hw4 /s/bach/j/under/jstrande/cs253/Hw4/CMakeFiles/hw4.tar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw4.tar.dir/depend

