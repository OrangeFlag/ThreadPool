# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/JetBrains/Clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/JetBrains/Clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab5.dir/flags.make

CMakeFiles/lab5.dir/main.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab5.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/main.cpp.o -c "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/main.cpp"

CMakeFiles/lab5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/main.cpp" > CMakeFiles/lab5.dir/main.cpp.i

CMakeFiles/lab5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/main.cpp" -o CMakeFiles/lab5.dir/main.cpp.s

CMakeFiles/lab5.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lab5.dir/main.cpp.o.requires

CMakeFiles/lab5.dir/main.cpp.o.provides: CMakeFiles/lab5.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/main.cpp.o.provides

CMakeFiles/lab5.dir/main.cpp.o.provides.build: CMakeFiles/lab5.dir/main.cpp.o


CMakeFiles/lab5.dir/Factorization.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/Factorization.cpp.o: ../Factorization.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab5.dir/Factorization.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/Factorization.cpp.o -c "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/Factorization.cpp"

CMakeFiles/lab5.dir/Factorization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/Factorization.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/Factorization.cpp" > CMakeFiles/lab5.dir/Factorization.cpp.i

CMakeFiles/lab5.dir/Factorization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/Factorization.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/Factorization.cpp" -o CMakeFiles/lab5.dir/Factorization.cpp.s

CMakeFiles/lab5.dir/Factorization.cpp.o.requires:

.PHONY : CMakeFiles/lab5.dir/Factorization.cpp.o.requires

CMakeFiles/lab5.dir/Factorization.cpp.o.provides: CMakeFiles/lab5.dir/Factorization.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/Factorization.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/Factorization.cpp.o.provides

CMakeFiles/lab5.dir/Factorization.cpp.o.provides.build: CMakeFiles/lab5.dir/Factorization.cpp.o


# Object files for target lab5
lab5_OBJECTS = \
"CMakeFiles/lab5.dir/main.cpp.o" \
"CMakeFiles/lab5.dir/Factorization.cpp.o"

# External object files for target lab5
lab5_EXTERNAL_OBJECTS =

lab5: CMakeFiles/lab5.dir/main.cpp.o
lab5: CMakeFiles/lab5.dir/Factorization.cpp.o
lab5: CMakeFiles/lab5.dir/build.make
lab5: CMakeFiles/lab5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab5.dir/build: lab5

.PHONY : CMakeFiles/lab5.dir/build

CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/main.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/Factorization.cpp.o.requires

.PHONY : CMakeFiles/lab5.dir/requires

CMakeFiles/lab5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab5.dir/clean

CMakeFiles/lab5.dir/depend:
	cd "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5" "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5" "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug" "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug" "/home/yorick/Work/Study/2 курс/1 семестр/ООП/Labs/lab5/cmake-build-debug/CMakeFiles/lab5.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab5.dir/depend

