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
CMAKE_SOURCE_DIR = /home/mobin/Desktop/t

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mobin/Desktop/t/bin

# Include any dependencies generated for this target.
include test/CMakeFiles/AmmunitionTEST.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/AmmunitionTEST.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/AmmunitionTEST.dir/flags.make

test/CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.o: test/CMakeFiles/AmmunitionTEST.dir/flags.make
test/CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.o: ../test/AmmunitionTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mobin/Desktop/t/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.o"
	cd /home/mobin/Desktop/t/bin/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.o -c /home/mobin/Desktop/t/test/AmmunitionTest.cpp

test/CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.i"
	cd /home/mobin/Desktop/t/bin/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mobin/Desktop/t/test/AmmunitionTest.cpp > CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.i

test/CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.s"
	cd /home/mobin/Desktop/t/bin/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mobin/Desktop/t/test/AmmunitionTest.cpp -o CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.s

# Object files for target AmmunitionTEST
AmmunitionTEST_OBJECTS = \
"CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.o"

# External object files for target AmmunitionTEST
AmmunitionTEST_EXTERNAL_OBJECTS =

test/AmmunitionTEST: test/CMakeFiles/AmmunitionTEST.dir/AmmunitionTest.cpp.o
test/AmmunitionTEST: test/CMakeFiles/AmmunitionTEST.dir/build.make
test/AmmunitionTEST: /usr/local/lib/libgtest.a
test/AmmunitionTEST: /usr/local/lib/libgtest_main.a
test/AmmunitionTEST: src/libmy.a
test/AmmunitionTEST: /usr/local/lib/libgtest.a
test/AmmunitionTEST: test/CMakeFiles/AmmunitionTEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mobin/Desktop/t/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AmmunitionTEST"
	cd /home/mobin/Desktop/t/bin/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AmmunitionTEST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/AmmunitionTEST.dir/build: test/AmmunitionTEST

.PHONY : test/CMakeFiles/AmmunitionTEST.dir/build

test/CMakeFiles/AmmunitionTEST.dir/clean:
	cd /home/mobin/Desktop/t/bin/test && $(CMAKE_COMMAND) -P CMakeFiles/AmmunitionTEST.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/AmmunitionTEST.dir/clean

test/CMakeFiles/AmmunitionTEST.dir/depend:
	cd /home/mobin/Desktop/t/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mobin/Desktop/t /home/mobin/Desktop/t/test /home/mobin/Desktop/t/bin /home/mobin/Desktop/t/bin/test /home/mobin/Desktop/t/bin/test/CMakeFiles/AmmunitionTEST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/AmmunitionTEST.dir/depend

