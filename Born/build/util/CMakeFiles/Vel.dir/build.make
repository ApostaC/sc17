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
CMAKE_SOURCE_DIR = /home/aposta/sc17/Born/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aposta/sc17/Born/build

# Include any dependencies generated for this target.
include util/CMakeFiles/Vel.dir/depend.make

# Include the progress variables for this target.
include util/CMakeFiles/Vel.dir/progress.make

# Include the compile flags for this target's objects.
include util/CMakeFiles/Vel.dir/flags.make

util/CMakeFiles/Vel.dir/Vel.cc.o: util/CMakeFiles/Vel.dir/flags.make
util/CMakeFiles/Vel.dir/Vel.cc.o: /home/aposta/sc17/Born/src/util/Vel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aposta/sc17/Born/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object util/CMakeFiles/Vel.dir/Vel.cc.o"
	cd /home/aposta/sc17/Born/build/util && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vel.dir/Vel.cc.o -c /home/aposta/sc17/Born/src/util/Vel.cc

util/CMakeFiles/Vel.dir/Vel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vel.dir/Vel.cc.i"
	cd /home/aposta/sc17/Born/build/util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aposta/sc17/Born/src/util/Vel.cc > CMakeFiles/Vel.dir/Vel.cc.i

util/CMakeFiles/Vel.dir/Vel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vel.dir/Vel.cc.s"
	cd /home/aposta/sc17/Born/build/util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aposta/sc17/Born/src/util/Vel.cc -o CMakeFiles/Vel.dir/Vel.cc.s

util/CMakeFiles/Vel.dir/Vel.cc.o.requires:

.PHONY : util/CMakeFiles/Vel.dir/Vel.cc.o.requires

util/CMakeFiles/Vel.dir/Vel.cc.o.provides: util/CMakeFiles/Vel.dir/Vel.cc.o.requires
	$(MAKE) -f util/CMakeFiles/Vel.dir/build.make util/CMakeFiles/Vel.dir/Vel.cc.o.provides.build
.PHONY : util/CMakeFiles/Vel.dir/Vel.cc.o.provides

util/CMakeFiles/Vel.dir/Vel.cc.o.provides.build: util/CMakeFiles/Vel.dir/Vel.cc.o


# Object files for target Vel
Vel_OBJECTS = \
"CMakeFiles/Vel.dir/Vel.cc.o"

# External object files for target Vel
Vel_EXTERNAL_OBJECTS =

util/Vel: util/CMakeFiles/Vel.dir/Vel.cc.o
util/Vel: util/CMakeFiles/Vel.dir/build.make
util/Vel: /opt/genericIO/lib/libgenericCpp.a
util/Vel: util/CMakeFiles/Vel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aposta/sc17/Born/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Vel"
	cd /home/aposta/sc17/Born/build/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
util/CMakeFiles/Vel.dir/build: util/Vel

.PHONY : util/CMakeFiles/Vel.dir/build

util/CMakeFiles/Vel.dir/requires: util/CMakeFiles/Vel.dir/Vel.cc.o.requires

.PHONY : util/CMakeFiles/Vel.dir/requires

util/CMakeFiles/Vel.dir/clean:
	cd /home/aposta/sc17/Born/build/util && $(CMAKE_COMMAND) -P CMakeFiles/Vel.dir/cmake_clean.cmake
.PHONY : util/CMakeFiles/Vel.dir/clean

util/CMakeFiles/Vel.dir/depend:
	cd /home/aposta/sc17/Born/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aposta/sc17/Born/src /home/aposta/sc17/Born/src/util /home/aposta/sc17/Born/build /home/aposta/sc17/Born/build/util /home/aposta/sc17/Born/build/util/CMakeFiles/Vel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : util/CMakeFiles/Vel.dir/depend

