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
include CMakeFiles/Model3D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Model3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Model3D.dir/flags.make

CMakeFiles/Model3D.dir/model.cc.o: CMakeFiles/Model3D.dir/flags.make
CMakeFiles/Model3D.dir/model.cc.o: /home/aposta/sc17/Born/src/model.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aposta/sc17/Born/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Model3D.dir/model.cc.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Model3D.dir/model.cc.o -c /home/aposta/sc17/Born/src/model.cc

CMakeFiles/Model3D.dir/model.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Model3D.dir/model.cc.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aposta/sc17/Born/src/model.cc > CMakeFiles/Model3D.dir/model.cc.i

CMakeFiles/Model3D.dir/model.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Model3D.dir/model.cc.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aposta/sc17/Born/src/model.cc -o CMakeFiles/Model3D.dir/model.cc.s

CMakeFiles/Model3D.dir/model.cc.o.requires:

.PHONY : CMakeFiles/Model3D.dir/model.cc.o.requires

CMakeFiles/Model3D.dir/model.cc.o.provides: CMakeFiles/Model3D.dir/model.cc.o.requires
	$(MAKE) -f CMakeFiles/Model3D.dir/build.make CMakeFiles/Model3D.dir/model.cc.o.provides.build
.PHONY : CMakeFiles/Model3D.dir/model.cc.o.provides

CMakeFiles/Model3D.dir/model.cc.o.provides.build: CMakeFiles/Model3D.dir/model.cc.o


# Object files for target Model3D
Model3D_OBJECTS = \
"CMakeFiles/Model3D.dir/model.cc.o"

# External object files for target Model3D
Model3D_EXTERNAL_OBJECTS =

Model3D: CMakeFiles/Model3D.dir/model.cc.o
Model3D: CMakeFiles/Model3D.dir/build.make
Model3D: base/libbase.a
Model3D: /opt/genericIO/lib/libgenericCpp.a
Model3D: /usr/lib/x86_64-linux-gnu/libtbb.so
Model3D: CMakeFiles/Model3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aposta/sc17/Born/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Model3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Model3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Model3D.dir/build: Model3D

.PHONY : CMakeFiles/Model3D.dir/build

CMakeFiles/Model3D.dir/requires: CMakeFiles/Model3D.dir/model.cc.o.requires

.PHONY : CMakeFiles/Model3D.dir/requires

CMakeFiles/Model3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Model3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Model3D.dir/clean

CMakeFiles/Model3D.dir/depend:
	cd /home/aposta/sc17/Born/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aposta/sc17/Born/src /home/aposta/sc17/Born/src /home/aposta/sc17/Born/build /home/aposta/sc17/Born/build /home/aposta/sc17/Born/build/CMakeFiles/Model3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Model3D.dir/depend

