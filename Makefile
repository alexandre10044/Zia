# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:



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
CMAKE_SOURCE_DIR = /home/tchezaud/Desktop/Rendu/CPP_zia_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tchezaud/Desktop/Rendu/CPP_zia_2019

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tchezaud/Desktop/Rendu/CPP_zia_2019/CMakeFiles /home/tchezaud/Desktop/Rendu/CPP_zia_2019/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tchezaud/Desktop/Rendu/CPP_zia_2019/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named zia_server

# Build rule for target.
zia_server: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 zia_server
.PHONY : zia_server

# fast build rule for target.
zia_server/fast:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/build
.PHONY : zia_server/fast

zia/Config/Config.o: zia/Config/Config.cpp.o

.PHONY : zia/Config/Config.o

# target to build an object file
zia/Config/Config.cpp.o:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Config/Config.cpp.o
.PHONY : zia/Config/Config.cpp.o

zia/Config/Config.i: zia/Config/Config.cpp.i

.PHONY : zia/Config/Config.i

# target to preprocess a source file
zia/Config/Config.cpp.i:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Config/Config.cpp.i
.PHONY : zia/Config/Config.cpp.i

zia/Config/Config.s: zia/Config/Config.cpp.s

.PHONY : zia/Config/Config.s

# target to generate assembly for a file
zia/Config/Config.cpp.s:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Config/Config.cpp.s
.PHONY : zia/Config/Config.cpp.s

zia/Log/Log.o: zia/Log/Log.cpp.o

.PHONY : zia/Log/Log.o

# target to build an object file
zia/Log/Log.cpp.o:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Log/Log.cpp.o
.PHONY : zia/Log/Log.cpp.o

zia/Log/Log.i: zia/Log/Log.cpp.i

.PHONY : zia/Log/Log.i

# target to preprocess a source file
zia/Log/Log.cpp.i:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Log/Log.cpp.i
.PHONY : zia/Log/Log.cpp.i

zia/Log/Log.s: zia/Log/Log.cpp.s

.PHONY : zia/Log/Log.s

# target to generate assembly for a file
zia/Log/Log.cpp.s:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Log/Log.cpp.s
.PHONY : zia/Log/Log.cpp.s

zia/Network/Client/Client.o: zia/Network/Client/Client.cpp.o

.PHONY : zia/Network/Client/Client.o

# target to build an object file
zia/Network/Client/Client.cpp.o:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Network/Client/Client.cpp.o
.PHONY : zia/Network/Client/Client.cpp.o

zia/Network/Client/Client.i: zia/Network/Client/Client.cpp.i

.PHONY : zia/Network/Client/Client.i

# target to preprocess a source file
zia/Network/Client/Client.cpp.i:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Network/Client/Client.cpp.i
.PHONY : zia/Network/Client/Client.cpp.i

zia/Network/Client/Client.s: zia/Network/Client/Client.cpp.s

.PHONY : zia/Network/Client/Client.s

# target to generate assembly for a file
zia/Network/Client/Client.cpp.s:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Network/Client/Client.cpp.s
.PHONY : zia/Network/Client/Client.cpp.s

zia/Network/NetworkManager.o: zia/Network/NetworkManager.cpp.o

.PHONY : zia/Network/NetworkManager.o

# target to build an object file
zia/Network/NetworkManager.cpp.o:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Network/NetworkManager.cpp.o
.PHONY : zia/Network/NetworkManager.cpp.o

zia/Network/NetworkManager.i: zia/Network/NetworkManager.cpp.i

.PHONY : zia/Network/NetworkManager.i

# target to preprocess a source file
zia/Network/NetworkManager.cpp.i:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Network/NetworkManager.cpp.i
.PHONY : zia/Network/NetworkManager.cpp.i

zia/Network/NetworkManager.s: zia/Network/NetworkManager.cpp.s

.PHONY : zia/Network/NetworkManager.s

# target to generate assembly for a file
zia/Network/NetworkManager.cpp.s:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/Network/NetworkManager.cpp.s
.PHONY : zia/Network/NetworkManager.cpp.s

zia/main.o: zia/main.cpp.o

.PHONY : zia/main.o

# target to build an object file
zia/main.cpp.o:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/main.cpp.o
.PHONY : zia/main.cpp.o

zia/main.i: zia/main.cpp.i

.PHONY : zia/main.i

# target to preprocess a source file
zia/main.cpp.i:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/main.cpp.i
.PHONY : zia/main.cpp.i

zia/main.s: zia/main.cpp.s

.PHONY : zia/main.s

# target to generate assembly for a file
zia/main.cpp.s:
	$(MAKE) -f CMakeFiles/zia_server.dir/build.make CMakeFiles/zia_server.dir/zia/main.cpp.s
.PHONY : zia/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... zia_server"
	@echo "... edit_cache"
	@echo "... zia/Config/Config.o"
	@echo "... zia/Config/Config.i"
	@echo "... zia/Config/Config.s"
	@echo "... zia/Log/Log.o"
	@echo "... zia/Log/Log.i"
	@echo "... zia/Log/Log.s"
	@echo "... zia/Network/Client/Client.o"
	@echo "... zia/Network/Client/Client.i"
	@echo "... zia/Network/Client/Client.s"
	@echo "... zia/Network/NetworkManager.o"
	@echo "... zia/Network/NetworkManager.i"
	@echo "... zia/Network/NetworkManager.s"
	@echo "... zia/main.o"
	@echo "... zia/main.i"
	@echo "... zia/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

