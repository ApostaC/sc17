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
include util/CMakeFiles/Add.dir/depend.make

# Include the progress variables for this target.
include util/CMakeFiles/Add.dir/progress.make

# Include the compile flags for this target's objects.
include util/CMakeFiles/Add.dir/flags.make

util/CMakeFiles/Add.dir/Add.cc.o: util/CMakeFiles/Add.dir/flags.make
util/CMakeFiles/Add.dir/Add.cc.o: /home/aposta/sc17/Born/src/util/Add.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aposta/sc17/Born/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object util/CMakeFiles/Add.dir/Add.cc.o"
	cd /home/aposta/sc17/Born/build/util && /usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Add.dir/Add.cc.o -c /home/aposta/sc17/Born/src/util/Add.cc

util/CMakeFiles/Add.dir/Add.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Add.dir/Add.cc.i"
	cd /home/aposta/sc17/Born/build/util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aposta/sc17/Born/src/util/Add.cc > CMakeFiles/Add.dir/Add.cc.i

util/CMakeFiles/Add.dir/Add.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Add.dir/Add.cc.s"
	cd /home/aposta/sc17/Born/build/util && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aposta/sc17/Born/src/util/Add.cc -o CMakeFiles/Add.dir/Add.cc.s

util/CMakeFiles/Add.dir/Add.cc.o.requires:

.PHONY : util/CMakeFiles/Add.dir/Add.cc.o.requires

util/CMakeFiles/Add.dir/Add.cc.o.provides: util/CMakeFiles/Add.dir/Add.cc.o.requires
	$(MAKE) -f util/CMakeFiles/Add.dir/build.make util/CMakeFiles/Add.dir/Add.cc.o.provides.build
.PHONY : util/CMakeFiles/Add.dir/Add.cc.o.provides

util/CMakeFiles/Add.dir/Add.cc.o.provides.build: util/CMakeFiles/Add.dir/Add.cc.o


# Object files for target Add
Add_OBJECTS = \
"CMakeFiles/Add.dir/Add.cc.o"

# External object files for target Add
Add_EXTERNAL_OBJECTS =

util/Add: util/CMakeFiles/Add.dir/Add.cc.o
util/Add: util/CMakeFiles/Add.dir/build.make
util/Add: /opt/genericIO/lib/libgenericCpp.a
util/Add: util/CMakeFiles/Add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aposta/sc17/Born/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Add"
	cd /home/aposta/sc17/Born/build/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Add.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
util/CMakeFiles/Add.dir/build: util/Add

.PHONY : util/CMakeFiles/Add.dir/build

util/CMakeFiles/Add.dir/requires: util/CMakeFiles/Add.dir/Add.cc.o.requires

.PHONY : util/CMakeFiles/Add.dir/requires

util/CMakeFiles/Add.dir/clean:
	cd /home/aposta/sc17/Born/build/util && $(CMAKE_COMMAND) -P CMakeFiles/Add.dir/cmake_clean.cmake
.PHONY : util/CMakeFiles/Add.dir/clean

util/CMakeFiles/Add.dir/depend:
	cd /home/aposta/sc17/Born/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aposta/sc17/Born/src /home/aposta/sc17/Born/src/util /home/aposta/sc17/Born/build /home/aposta/sc17/Born/build/util /home/aposta/sc17/Born/build/util/CMakeFiles/Add.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : util/CMakeFiles/Add.dir/depend

