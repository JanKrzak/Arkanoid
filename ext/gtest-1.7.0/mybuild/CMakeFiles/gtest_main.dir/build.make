# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.1

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
CMAKE_COMMAND = "/c/Program Files (x86)/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "/c/Program Files (x86)/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild

# Include any dependencies generated for this target.
include CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest_main.dir/flags.make

CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: CMakeFiles/gtest_main.dir/flags.make
CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: CMakeFiles/gtest_main.dir/includes_CXX.rsp
CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: ../src/gtest_main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"
	/c/TDM-GCC-32/bin/g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj -c /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/src/gtest_main.cc

CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	/c/TDM-GCC-32/bin/g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	/c/TDM-GCC-32/bin/g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires:
.PHONY : CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires

CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides: CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires
	$(MAKE) -f CMakeFiles/gtest_main.dir/build.make CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides.build
.PHONY : CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides

CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides.build: CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

libgtest_main.a: CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj
libgtest_main.a: CMakeFiles/gtest_main.dir/build.make
libgtest_main.a: CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgtest_main.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest_main.dir/build: libgtest_main.a
.PHONY : CMakeFiles/gtest_main.dir/build

CMakeFiles/gtest_main.dir/requires: CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires
.PHONY : CMakeFiles/gtest_main.dir/requires

CMakeFiles/gtest_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest_main.dir/clean

CMakeFiles/gtest_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0 /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0 /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest_main.dir/depend

