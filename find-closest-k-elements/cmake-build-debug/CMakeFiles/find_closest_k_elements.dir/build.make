# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/find_closest_k_elements.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/find_closest_k_elements.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/find_closest_k_elements.dir/flags.make

CMakeFiles/find_closest_k_elements.dir/main.cpp.obj: CMakeFiles/find_closest_k_elements.dir/flags.make
CMakeFiles/find_closest_k_elements.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/find_closest_k_elements.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\find_closest_k_elements.dir\main.cpp.obj -c C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\main.cpp

CMakeFiles/find_closest_k_elements.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/find_closest_k_elements.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\main.cpp > CMakeFiles\find_closest_k_elements.dir\main.cpp.i

CMakeFiles/find_closest_k_elements.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/find_closest_k_elements.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\main.cpp -o CMakeFiles\find_closest_k_elements.dir\main.cpp.s

# Object files for target find_closest_k_elements
find_closest_k_elements_OBJECTS = \
"CMakeFiles/find_closest_k_elements.dir/main.cpp.obj"

# External object files for target find_closest_k_elements
find_closest_k_elements_EXTERNAL_OBJECTS =

find_closest_k_elements.exe: CMakeFiles/find_closest_k_elements.dir/main.cpp.obj
find_closest_k_elements.exe: CMakeFiles/find_closest_k_elements.dir/build.make
find_closest_k_elements.exe: CMakeFiles/find_closest_k_elements.dir/linklibs.rsp
find_closest_k_elements.exe: CMakeFiles/find_closest_k_elements.dir/objects1.rsp
find_closest_k_elements.exe: CMakeFiles/find_closest_k_elements.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable find_closest_k_elements.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\find_closest_k_elements.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/find_closest_k_elements.dir/build: find_closest_k_elements.exe

.PHONY : CMakeFiles/find_closest_k_elements.dir/build

CMakeFiles/find_closest_k_elements.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\find_closest_k_elements.dir\cmake_clean.cmake
.PHONY : CMakeFiles/find_closest_k_elements.dir/clean

CMakeFiles/find_closest_k_elements.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\cmake-build-debug C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\cmake-build-debug C:\Users\lu.gao\Desktop\learning-algo-week-3-binary-search\find-closest-k-elements\cmake-build-debug\CMakeFiles\find_closest_k_elements.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/find_closest_k_elements.dir/depend
