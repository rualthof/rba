# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/perfil/Desktop/rudi/googletest-release-1.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/perfil/Desktop/rudi/googletest-release-1.7.0

# Include any dependencies generated for this target.
include CMakeFiles/sample3_unittest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sample3_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sample3_unittest.dir/flags.make

CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o: CMakeFiles/sample3_unittest.dir/flags.make
CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o: samples/sample3_unittest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/perfil/Desktop/rudi/googletest-release-1.7.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o -c /home/perfil/Desktop/rudi/googletest-release-1.7.0/samples/sample3_unittest.cc

CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/perfil/Desktop/rudi/googletest-release-1.7.0/samples/sample3_unittest.cc > CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.i

CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/perfil/Desktop/rudi/googletest-release-1.7.0/samples/sample3_unittest.cc -o CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.s

CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.requires:

.PHONY : CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.requires

CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.provides: CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.requires
	$(MAKE) -f CMakeFiles/sample3_unittest.dir/build.make CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.provides.build
.PHONY : CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.provides

CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.provides.build: CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o


# Object files for target sample3_unittest
sample3_unittest_OBJECTS = \
"CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o"

# External object files for target sample3_unittest
sample3_unittest_EXTERNAL_OBJECTS =

sample3_unittest: CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o
sample3_unittest: CMakeFiles/sample3_unittest.dir/build.make
sample3_unittest: libgtest_main.so
sample3_unittest: libgtest.so
sample3_unittest: CMakeFiles/sample3_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/perfil/Desktop/rudi/googletest-release-1.7.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sample3_unittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample3_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sample3_unittest.dir/build: sample3_unittest

.PHONY : CMakeFiles/sample3_unittest.dir/build

CMakeFiles/sample3_unittest.dir/requires: CMakeFiles/sample3_unittest.dir/samples/sample3_unittest.cc.o.requires

.PHONY : CMakeFiles/sample3_unittest.dir/requires

CMakeFiles/sample3_unittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sample3_unittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sample3_unittest.dir/clean

CMakeFiles/sample3_unittest.dir/depend:
	cd /home/perfil/Desktop/rudi/googletest-release-1.7.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/perfil/Desktop/rudi/googletest-release-1.7.0 /home/perfil/Desktop/rudi/googletest-release-1.7.0 /home/perfil/Desktop/rudi/googletest-release-1.7.0 /home/perfil/Desktop/rudi/googletest-release-1.7.0 /home/perfil/Desktop/rudi/googletest-release-1.7.0/CMakeFiles/sample3_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sample3_unittest.dir/depend

