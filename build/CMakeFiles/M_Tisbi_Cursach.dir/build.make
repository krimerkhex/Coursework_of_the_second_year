# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Coursework_of_the_second_year\Cursach

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Coursework_of_the_second_year\build

# Include any dependencies generated for this target.
include CMakeFiles/M_Tisbi_Cursach.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/M_Tisbi_Cursach.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/M_Tisbi_Cursach.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/M_Tisbi_Cursach.dir/flags.make

CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.obj: CMakeFiles/M_Tisbi_Cursach.dir/flags.make
CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.obj: C:/Coursework_of_the_second_year/Cursach/main.cpp
CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.obj: CMakeFiles/M_Tisbi_Cursach.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Coursework_of_the_second_year\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.obj -MF CMakeFiles\M_Tisbi_Cursach.dir\main.cpp.obj.d -o CMakeFiles\M_Tisbi_Cursach.dir\main.cpp.obj -c C:\Coursework_of_the_second_year\Cursach\main.cpp

CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Coursework_of_the_second_year\Cursach\main.cpp > CMakeFiles\M_Tisbi_Cursach.dir\main.cpp.i

CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Coursework_of_the_second_year\Cursach\main.cpp -o CMakeFiles\M_Tisbi_Cursach.dir\main.cpp.s

# Object files for target M_Tisbi_Cursach
M_Tisbi_Cursach_OBJECTS = \
"CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.obj"

# External object files for target M_Tisbi_Cursach
M_Tisbi_Cursach_EXTERNAL_OBJECTS =

M_Tisbi_Cursach.exe: CMakeFiles/M_Tisbi_Cursach.dir/main.cpp.obj
M_Tisbi_Cursach.exe: CMakeFiles/M_Tisbi_Cursach.dir/build.make
M_Tisbi_Cursach.exe: CMakeFiles/M_Tisbi_Cursach.dir/linkLibs.rsp
M_Tisbi_Cursach.exe: CMakeFiles/M_Tisbi_Cursach.dir/objects1.rsp
M_Tisbi_Cursach.exe: CMakeFiles/M_Tisbi_Cursach.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Coursework_of_the_second_year\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable M_Tisbi_Cursach.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\M_Tisbi_Cursach.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/M_Tisbi_Cursach.dir/build: M_Tisbi_Cursach.exe
.PHONY : CMakeFiles/M_Tisbi_Cursach.dir/build

CMakeFiles/M_Tisbi_Cursach.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\M_Tisbi_Cursach.dir\cmake_clean.cmake
.PHONY : CMakeFiles/M_Tisbi_Cursach.dir/clean

CMakeFiles/M_Tisbi_Cursach.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Coursework_of_the_second_year\Cursach C:\Coursework_of_the_second_year\Cursach C:\Coursework_of_the_second_year\build C:\Coursework_of_the_second_year\build C:\Coursework_of_the_second_year\build\CMakeFiles\M_Tisbi_Cursach.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/M_Tisbi_Cursach.dir/depend
