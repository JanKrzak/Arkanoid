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
include CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest.dir/flags.make

CMakeFiles/gtest.dir/src/gtest-all.cc.obj: CMakeFiles/gtest.dir/flags.make
CMakeFiles/gtest.dir/src/gtest-all.cc.obj: CMakeFiles/gtest.dir/includes_CXX.rsp
CMakeFiles/gtest.dir/src/gtest-all.cc.obj: ../src/gtest-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	/c/TDM-GCC-32/bin/g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.obj -c /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/src/gtest-all.cc

CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	/c/TDM-GCC-32/bin/g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	/c/TDM-GCC-32/bin/g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires:
.PHONY : CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires

CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides: CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires
	$(MAKE) -f CMakeFiles/gtest.dir/build.make CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build
.PHONY : CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides

CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build: CMakeFiles/gtest.dir/src/gtest-all.cc.obj

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

libgtest.a: CMakeFiles/gtest.dir/src/gtest-all.cc.obj
libgtest.a: CMakeFiles/gtest.dir/build.make
libgtest.a: CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgtest.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest.dir/build: libgtest.a
.PHONY : CMakeFiles/gtest.dir/build

CMakeFiles/gtest.dir/requires: CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires
.PHONY : CMakeFiles/gtest.dir/requires

CMakeFiles/gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest.dir/clean

CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0 /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0 /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild /C/Users/tuziakar/Downloads/gtest-1.7.0/gtest-1.7.0/mybuild/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest.dir/depend

