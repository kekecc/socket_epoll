# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kk/Desktop/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kk/Desktop/server/build

# Include any dependencies generated for this target.
include src/CMakeFiles/MYTCP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/MYTCP.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MYTCP.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MYTCP.dir/flags.make

src/CMakeFiles/MYTCP.dir/epoll.cpp.o: src/CMakeFiles/MYTCP.dir/flags.make
src/CMakeFiles/MYTCP.dir/epoll.cpp.o: /home/kk/Desktop/server/src/epoll.cpp
src/CMakeFiles/MYTCP.dir/epoll.cpp.o: src/CMakeFiles/MYTCP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kk/Desktop/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/MYTCP.dir/epoll.cpp.o"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/MYTCP.dir/epoll.cpp.o -MF CMakeFiles/MYTCP.dir/epoll.cpp.o.d -o CMakeFiles/MYTCP.dir/epoll.cpp.o -c /home/kk/Desktop/server/src/epoll.cpp

src/CMakeFiles/MYTCP.dir/epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MYTCP.dir/epoll.cpp.i"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kk/Desktop/server/src/epoll.cpp > CMakeFiles/MYTCP.dir/epoll.cpp.i

src/CMakeFiles/MYTCP.dir/epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MYTCP.dir/epoll.cpp.s"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kk/Desktop/server/src/epoll.cpp -o CMakeFiles/MYTCP.dir/epoll.cpp.s

src/CMakeFiles/MYTCP.dir/socket.cpp.o: src/CMakeFiles/MYTCP.dir/flags.make
src/CMakeFiles/MYTCP.dir/socket.cpp.o: /home/kk/Desktop/server/src/socket.cpp
src/CMakeFiles/MYTCP.dir/socket.cpp.o: src/CMakeFiles/MYTCP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kk/Desktop/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/MYTCP.dir/socket.cpp.o"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/MYTCP.dir/socket.cpp.o -MF CMakeFiles/MYTCP.dir/socket.cpp.o.d -o CMakeFiles/MYTCP.dir/socket.cpp.o -c /home/kk/Desktop/server/src/socket.cpp

src/CMakeFiles/MYTCP.dir/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MYTCP.dir/socket.cpp.i"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kk/Desktop/server/src/socket.cpp > CMakeFiles/MYTCP.dir/socket.cpp.i

src/CMakeFiles/MYTCP.dir/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MYTCP.dir/socket.cpp.s"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kk/Desktop/server/src/socket.cpp -o CMakeFiles/MYTCP.dir/socket.cpp.s

src/CMakeFiles/MYTCP.dir/tcpserver.cpp.o: src/CMakeFiles/MYTCP.dir/flags.make
src/CMakeFiles/MYTCP.dir/tcpserver.cpp.o: /home/kk/Desktop/server/src/tcpserver.cpp
src/CMakeFiles/MYTCP.dir/tcpserver.cpp.o: src/CMakeFiles/MYTCP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kk/Desktop/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/MYTCP.dir/tcpserver.cpp.o"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/MYTCP.dir/tcpserver.cpp.o -MF CMakeFiles/MYTCP.dir/tcpserver.cpp.o.d -o CMakeFiles/MYTCP.dir/tcpserver.cpp.o -c /home/kk/Desktop/server/src/tcpserver.cpp

src/CMakeFiles/MYTCP.dir/tcpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MYTCP.dir/tcpserver.cpp.i"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kk/Desktop/server/src/tcpserver.cpp > CMakeFiles/MYTCP.dir/tcpserver.cpp.i

src/CMakeFiles/MYTCP.dir/tcpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MYTCP.dir/tcpserver.cpp.s"
	cd /home/kk/Desktop/server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kk/Desktop/server/src/tcpserver.cpp -o CMakeFiles/MYTCP.dir/tcpserver.cpp.s

# Object files for target MYTCP
MYTCP_OBJECTS = \
"CMakeFiles/MYTCP.dir/epoll.cpp.o" \
"CMakeFiles/MYTCP.dir/socket.cpp.o" \
"CMakeFiles/MYTCP.dir/tcpserver.cpp.o"

# External object files for target MYTCP
MYTCP_EXTERNAL_OBJECTS =

src/libMYTCP.a: src/CMakeFiles/MYTCP.dir/epoll.cpp.o
src/libMYTCP.a: src/CMakeFiles/MYTCP.dir/socket.cpp.o
src/libMYTCP.a: src/CMakeFiles/MYTCP.dir/tcpserver.cpp.o
src/libMYTCP.a: src/CMakeFiles/MYTCP.dir/build.make
src/libMYTCP.a: src/CMakeFiles/MYTCP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kk/Desktop/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libMYTCP.a"
	cd /home/kk/Desktop/server/build/src && $(CMAKE_COMMAND) -P CMakeFiles/MYTCP.dir/cmake_clean_target.cmake
	cd /home/kk/Desktop/server/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MYTCP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/MYTCP.dir/build: src/libMYTCP.a
.PHONY : src/CMakeFiles/MYTCP.dir/build

src/CMakeFiles/MYTCP.dir/clean:
	cd /home/kk/Desktop/server/build/src && $(CMAKE_COMMAND) -P CMakeFiles/MYTCP.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/MYTCP.dir/clean

src/CMakeFiles/MYTCP.dir/depend:
	cd /home/kk/Desktop/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kk/Desktop/server /home/kk/Desktop/server/src /home/kk/Desktop/server/build /home/kk/Desktop/server/build/src /home/kk/Desktop/server/build/src/CMakeFiles/MYTCP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MYTCP.dir/depend

