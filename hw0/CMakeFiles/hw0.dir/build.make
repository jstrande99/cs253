# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /s/bach/j/under/jstrande/compSci253/hw0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/bach/j/under/jstrande/compSci253/hw0

# Include any dependencies generated for this target.
include CMakeFiles/hw0.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hw0.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hw0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw0.dir/flags.make

CMakeFiles/hw0.dir/main.cc.o: CMakeFiles/hw0.dir/flags.make
CMakeFiles/hw0.dir/main.cc.o: main.cc
CMakeFiles/hw0.dir/main.cc.o: CMakeFiles/hw0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/s/bach/j/under/jstrande/compSci253/hw0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw0.dir/main.cc.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw0.dir/main.cc.o -MF CMakeFiles/hw0.dir/main.cc.o.d -o CMakeFiles/hw0.dir/main.cc.o -c /s/bach/j/under/jstrande/compSci253/hw0/main.cc

CMakeFiles/hw0.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw0.dir/main.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /s/bach/j/under/jstrande/compSci253/hw0/main.cc > CMakeFiles/hw0.dir/main.cc.i

CMakeFiles/hw0.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw0.dir/main.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /s/bach/j/under/jstrande/compSci253/hw0/main.cc -o CMakeFiles/hw0.dir/main.cc.s

# Object files for target hw0
hw0_OBJECTS = \
"CMakeFiles/hw0.dir/main.cc.o"

# External object files for target hw0
hw0_EXTERNAL_OBJECTS =

hw0: CMakeFiles/hw0.dir/main.cc.o
hw0: CMakeFiles/hw0.dir/build.make
hw0: CMakeFiles/hw0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/s/bach/j/under/jstrande/compSci253/hw0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw0.dir/build: hw0
.PHONY : CMakeFiles/hw0.dir/build

CMakeFiles/hw0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw0.dir/clean

CMakeFiles/hw0.dir/depend:
	cd /s/bach/j/under/jstrande/compSci253/hw0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/bach/j/under/jstrande/compSci253/hw0 /s/bach/j/under/jstrande/compSci253/hw0 /s/bach/j/under/jstrande/compSci253/hw0 /s/bach/j/under/jstrande/compSci253/hw0 /s/bach/j/under/jstrande/compSci253/hw0/CMakeFiles/hw0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw0.dir/depend
