# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_redis++.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_redis++.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_redis++.dir/flags.make

test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o: test/CMakeFiles/test_redis++.dir/flags.make
test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o: ../test/src/sw/redis++/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o"
	cd /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o -c /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/test/src/sw/redis++/test_main.cpp

test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.i"
	cd /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/test/src/sw/redis++/test_main.cpp > CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.i

test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.s"
	cd /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/test/src/sw/redis++/test_main.cpp -o CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.s

test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.requires:

.PHONY : test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.requires

test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.provides: test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/test_redis++.dir/build.make test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.provides.build
.PHONY : test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.provides

test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.provides.build: test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o


# Object files for target test_redis++
test_redis_______OBJECTS = \
"CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o"

# External object files for target test_redis++
test_redis_______EXTERNAL_OBJECTS =

test/test_redis++: test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o
test/test_redis++: test/CMakeFiles/test_redis++.dir/build.make
test/test_redis++: /usr/local/lib/libhiredis.a
test/test_redis++: libredis++.a
test/test_redis++: test/CMakeFiles/test_redis++.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_redis++"
	cd /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_redis++.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_redis++.dir/build: test/test_redis++

.PHONY : test/CMakeFiles/test_redis++.dir/build

test/CMakeFiles/test_redis++.dir/requires: test/CMakeFiles/test_redis++.dir/src/sw/redis++/test_main.cpp.o.requires

.PHONY : test/CMakeFiles/test_redis++.dir/requires

test/CMakeFiles/test_redis++.dir/clean:
	cd /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_redis++.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_redis++.dir/clean

test/CMakeFiles/test_redis++.dir/depend:
	cd /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/test /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test/CMakeFiles/test_redis++.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_redis++.dir/depend

