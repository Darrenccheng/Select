# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/computer_Study/IO/SelectDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/computer_Study/IO/SelectDemo/build

# Include any dependencies generated for this target.
include CMakeFiles/SelectClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SelectClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SelectClient.dir/flags.make

CMakeFiles/SelectClient.dir/select_client.cpp.o: CMakeFiles/SelectClient.dir/flags.make
CMakeFiles/SelectClient.dir/select_client.cpp.o: ../select_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/computer_Study/IO/SelectDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SelectClient.dir/select_client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SelectClient.dir/select_client.cpp.o -c /home/computer_Study/IO/SelectDemo/select_client.cpp

CMakeFiles/SelectClient.dir/select_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelectClient.dir/select_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/computer_Study/IO/SelectDemo/select_client.cpp > CMakeFiles/SelectClient.dir/select_client.cpp.i

CMakeFiles/SelectClient.dir/select_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelectClient.dir/select_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/computer_Study/IO/SelectDemo/select_client.cpp -o CMakeFiles/SelectClient.dir/select_client.cpp.s

# Object files for target SelectClient
SelectClient_OBJECTS = \
"CMakeFiles/SelectClient.dir/select_client.cpp.o"

# External object files for target SelectClient
SelectClient_EXTERNAL_OBJECTS =

../bin/SelectClient: CMakeFiles/SelectClient.dir/select_client.cpp.o
../bin/SelectClient: CMakeFiles/SelectClient.dir/build.make
../bin/SelectClient: CMakeFiles/SelectClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/computer_Study/IO/SelectDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/SelectClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SelectClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SelectClient.dir/build: ../bin/SelectClient

.PHONY : CMakeFiles/SelectClient.dir/build

CMakeFiles/SelectClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SelectClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SelectClient.dir/clean

CMakeFiles/SelectClient.dir/depend:
	cd /home/computer_Study/IO/SelectDemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/computer_Study/IO/SelectDemo /home/computer_Study/IO/SelectDemo /home/computer_Study/IO/SelectDemo/build /home/computer_Study/IO/SelectDemo/build /home/computer_Study/IO/SelectDemo/build/CMakeFiles/SelectClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SelectClient.dir/depend
