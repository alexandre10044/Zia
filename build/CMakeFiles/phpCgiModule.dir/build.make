# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/thomasc/Rendu/2019/CPP_zia_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomasc/Rendu/2019/CPP_zia_2019/build

# Include any dependencies generated for this target.
include CMakeFiles/phpCgiModule.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/phpCgiModule.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/phpCgiModule.dir/flags.make

CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.o: CMakeFiles/phpCgiModule.dir/flags.make
CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.o: ../modules/phpCgiModule/Php.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomasc/Rendu/2019/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.o -c /home/thomasc/Rendu/2019/CPP_zia_2019/modules/phpCgiModule/Php.cpp

CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomasc/Rendu/2019/CPP_zia_2019/modules/phpCgiModule/Php.cpp > CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.i

CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomasc/Rendu/2019/CPP_zia_2019/modules/phpCgiModule/Php.cpp -o CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.s

# Object files for target phpCgiModule
phpCgiModule_OBJECTS = \
"CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.o"

# External object files for target phpCgiModule
phpCgiModule_EXTERNAL_OBJECTS =

modules/libphpCgiModule.so: CMakeFiles/phpCgiModule.dir/modules/phpCgiModule/Php.cpp.o
modules/libphpCgiModule.so: CMakeFiles/phpCgiModule.dir/build.make
modules/libphpCgiModule.so: libopenZia.a
modules/libphpCgiModule.so: CMakeFiles/phpCgiModule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomasc/Rendu/2019/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library modules/libphpCgiModule.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phpCgiModule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/phpCgiModule.dir/build: modules/libphpCgiModule.so

.PHONY : CMakeFiles/phpCgiModule.dir/build

CMakeFiles/phpCgiModule.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/phpCgiModule.dir/cmake_clean.cmake
.PHONY : CMakeFiles/phpCgiModule.dir/clean

CMakeFiles/phpCgiModule.dir/depend:
	cd /home/thomasc/Rendu/2019/CPP_zia_2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomasc/Rendu/2019/CPP_zia_2019 /home/thomasc/Rendu/2019/CPP_zia_2019 /home/thomasc/Rendu/2019/CPP_zia_2019/build /home/thomasc/Rendu/2019/CPP_zia_2019/build /home/thomasc/Rendu/2019/CPP_zia_2019/build/CMakeFiles/phpCgiModule.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/phpCgiModule.dir/depend
