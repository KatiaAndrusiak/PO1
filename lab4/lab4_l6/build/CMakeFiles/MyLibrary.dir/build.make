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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/katya/PO1/lab4/lab4_l6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/katya/PO1/lab4/lab4_l6/build

# Include any dependencies generated for this target.
include CMakeFiles/MyLibrary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyLibrary.dir/flags.make

CMakeFiles/MyLibrary.dir/src/matrix.cpp.o: CMakeFiles/MyLibrary.dir/flags.make
CMakeFiles/MyLibrary.dir/src/matrix.cpp.o: ../src/matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/katya/PO1/lab4/lab4_l6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyLibrary.dir/src/matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyLibrary.dir/src/matrix.cpp.o -c /home/katya/PO1/lab4/lab4_l6/src/matrix.cpp

CMakeFiles/MyLibrary.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyLibrary.dir/src/matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/katya/PO1/lab4/lab4_l6/src/matrix.cpp > CMakeFiles/MyLibrary.dir/src/matrix.cpp.i

CMakeFiles/MyLibrary.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyLibrary.dir/src/matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/katya/PO1/lab4/lab4_l6/src/matrix.cpp -o CMakeFiles/MyLibrary.dir/src/matrix.cpp.s

CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.requires:

.PHONY : CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.requires

CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.provides: CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyLibrary.dir/build.make CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.provides.build
.PHONY : CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.provides

CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.provides.build: CMakeFiles/MyLibrary.dir/src/matrix.cpp.o


CMakeFiles/MyLibrary.dir/src/vector.cpp.o: CMakeFiles/MyLibrary.dir/flags.make
CMakeFiles/MyLibrary.dir/src/vector.cpp.o: ../src/vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/katya/PO1/lab4/lab4_l6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyLibrary.dir/src/vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyLibrary.dir/src/vector.cpp.o -c /home/katya/PO1/lab4/lab4_l6/src/vector.cpp

CMakeFiles/MyLibrary.dir/src/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyLibrary.dir/src/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/katya/PO1/lab4/lab4_l6/src/vector.cpp > CMakeFiles/MyLibrary.dir/src/vector.cpp.i

CMakeFiles/MyLibrary.dir/src/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyLibrary.dir/src/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/katya/PO1/lab4/lab4_l6/src/vector.cpp -o CMakeFiles/MyLibrary.dir/src/vector.cpp.s

CMakeFiles/MyLibrary.dir/src/vector.cpp.o.requires:

.PHONY : CMakeFiles/MyLibrary.dir/src/vector.cpp.o.requires

CMakeFiles/MyLibrary.dir/src/vector.cpp.o.provides: CMakeFiles/MyLibrary.dir/src/vector.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyLibrary.dir/build.make CMakeFiles/MyLibrary.dir/src/vector.cpp.o.provides.build
.PHONY : CMakeFiles/MyLibrary.dir/src/vector.cpp.o.provides

CMakeFiles/MyLibrary.dir/src/vector.cpp.o.provides.build: CMakeFiles/MyLibrary.dir/src/vector.cpp.o


# Object files for target MyLibrary
MyLibrary_OBJECTS = \
"CMakeFiles/MyLibrary.dir/src/matrix.cpp.o" \
"CMakeFiles/MyLibrary.dir/src/vector.cpp.o"

# External object files for target MyLibrary
MyLibrary_EXTERNAL_OBJECTS =

libMyLibrary.a: CMakeFiles/MyLibrary.dir/src/matrix.cpp.o
libMyLibrary.a: CMakeFiles/MyLibrary.dir/src/vector.cpp.o
libMyLibrary.a: CMakeFiles/MyLibrary.dir/build.make
libMyLibrary.a: CMakeFiles/MyLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/katya/PO1/lab4/lab4_l6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libMyLibrary.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MyLibrary.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyLibrary.dir/build: libMyLibrary.a

.PHONY : CMakeFiles/MyLibrary.dir/build

CMakeFiles/MyLibrary.dir/requires: CMakeFiles/MyLibrary.dir/src/matrix.cpp.o.requires
CMakeFiles/MyLibrary.dir/requires: CMakeFiles/MyLibrary.dir/src/vector.cpp.o.requires

.PHONY : CMakeFiles/MyLibrary.dir/requires

CMakeFiles/MyLibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyLibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyLibrary.dir/clean

CMakeFiles/MyLibrary.dir/depend:
	cd /home/katya/PO1/lab4/lab4_l6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/katya/PO1/lab4/lab4_l6 /home/katya/PO1/lab4/lab4_l6 /home/katya/PO1/lab4/lab4_l6/build /home/katya/PO1/lab4/lab4_l6/build /home/katya/PO1/lab4/lab4_l6/build/CMakeFiles/MyLibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyLibrary.dir/depend

