# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mattc/hackathon/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mattc/hackathon/src

# Include any dependencies generated for this target.
include CMakeFiles/umbrella.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/umbrella.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/umbrella.dir/flags.make

CMakeFiles/umbrella.dir/src/sample1.cpp.o: CMakeFiles/umbrella.dir/flags.make
CMakeFiles/umbrella.dir/src/sample1.cpp.o: src/sample1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mattc/hackathon/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/umbrella.dir/src/sample1.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/umbrella.dir/src/sample1.cpp.o -c /Users/mattc/hackathon/src/src/sample1.cpp

CMakeFiles/umbrella.dir/src/sample1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/umbrella.dir/src/sample1.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattc/hackathon/src/src/sample1.cpp > CMakeFiles/umbrella.dir/src/sample1.cpp.i

CMakeFiles/umbrella.dir/src/sample1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/umbrella.dir/src/sample1.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattc/hackathon/src/src/sample1.cpp -o CMakeFiles/umbrella.dir/src/sample1.cpp.s

# Object files for target umbrella
umbrella_OBJECTS = \
"CMakeFiles/umbrella.dir/src/sample1.cpp.o"

# External object files for target umbrella
umbrella_EXTERNAL_OBJECTS =

umbrella: CMakeFiles/umbrella.dir/src/sample1.cpp.o
umbrella: CMakeFiles/umbrella.dir/build.make
umbrella: CMakeFiles/umbrella.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mattc/hackathon/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable umbrella"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/umbrella.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/umbrella.dir/build: umbrella

.PHONY : CMakeFiles/umbrella.dir/build

CMakeFiles/umbrella.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/umbrella.dir/cmake_clean.cmake
.PHONY : CMakeFiles/umbrella.dir/clean

CMakeFiles/umbrella.dir/depend:
	cd /Users/mattc/hackathon/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mattc/hackathon/src /Users/mattc/hackathon/src /Users/mattc/hackathon/src /Users/mattc/hackathon/src /Users/mattc/hackathon/src/CMakeFiles/umbrella.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/umbrella.dir/depend

