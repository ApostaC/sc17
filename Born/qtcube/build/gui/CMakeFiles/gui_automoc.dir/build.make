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
CMAKE_SOURCE_DIR = /home/aposta/sc17/Born/qtcube/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aposta/sc17/Born/qtcube/build

# Utility rule file for gui_automoc.

# Include the progress variables for this target.
include gui/CMakeFiles/gui_automoc.dir/progress.make

gui/CMakeFiles/gui_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aposta/sc17/Born/qtcube/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc for target gui"
	cd /home/aposta/sc17/Born/qtcube/build/gui && /usr/bin/cmake -E cmake_autogen /home/aposta/sc17/Born/qtcube/build/gui/CMakeFiles/gui_automoc.dir/ ""

gui_automoc: gui/CMakeFiles/gui_automoc
gui_automoc: gui/CMakeFiles/gui_automoc.dir/build.make

.PHONY : gui_automoc

# Rule to build all files generated by this target.
gui/CMakeFiles/gui_automoc.dir/build: gui_automoc

.PHONY : gui/CMakeFiles/gui_automoc.dir/build

gui/CMakeFiles/gui_automoc.dir/clean:
	cd /home/aposta/sc17/Born/qtcube/build/gui && $(CMAKE_COMMAND) -P CMakeFiles/gui_automoc.dir/cmake_clean.cmake
.PHONY : gui/CMakeFiles/gui_automoc.dir/clean

gui/CMakeFiles/gui_automoc.dir/depend:
	cd /home/aposta/sc17/Born/qtcube/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aposta/sc17/Born/qtcube/src /home/aposta/sc17/Born/qtcube/src/gui /home/aposta/sc17/Born/qtcube/build /home/aposta/sc17/Born/qtcube/build/gui /home/aposta/sc17/Born/qtcube/build/gui/CMakeFiles/gui_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gui/CMakeFiles/gui_automoc.dir/depend

