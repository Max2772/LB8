# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/user/Documents/453502/ОАиП/LabWork_8/Task_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/main.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/main.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/main.cpp
CMakeFiles/app.dir/main.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/main.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/main.cpp.o -MF CMakeFiles/app.dir/main.cpp.o.d -o CMakeFiles/app.dir/main.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/main.cpp

CMakeFiles/app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/main.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/main.cpp > CMakeFiles/app.dir/main.cpp.i

CMakeFiles/app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/main.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/main.cpp -o CMakeFiles/app.dir/main.cpp.s

CMakeFiles/app.dir/array_utils.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/array_utils.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/array_utils.cpp
CMakeFiles/app.dir/array_utils.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/app.dir/array_utils.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/array_utils.cpp.o -MF CMakeFiles/app.dir/array_utils.cpp.o.d -o CMakeFiles/app.dir/array_utils.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/array_utils.cpp

CMakeFiles/app.dir/array_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/array_utils.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/array_utils.cpp > CMakeFiles/app.dir/array_utils.cpp.i

CMakeFiles/app.dir/array_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/array_utils.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/array_utils.cpp -o CMakeFiles/app.dir/array_utils.cpp.s

CMakeFiles/app.dir/input.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/input.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/input.cpp
CMakeFiles/app.dir/input.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/app.dir/input.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/input.cpp.o -MF CMakeFiles/app.dir/input.cpp.o.d -o CMakeFiles/app.dir/input.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/input.cpp

CMakeFiles/app.dir/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/input.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/input.cpp > CMakeFiles/app.dir/input.cpp.i

CMakeFiles/app.dir/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/input.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/input.cpp -o CMakeFiles/app.dir/input.cpp.s

CMakeFiles/app.dir/logic.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/logic.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/logic.cpp
CMakeFiles/app.dir/logic.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/app.dir/logic.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/logic.cpp.o -MF CMakeFiles/app.dir/logic.cpp.o.d -o CMakeFiles/app.dir/logic.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/logic.cpp

CMakeFiles/app.dir/logic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/logic.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/logic.cpp > CMakeFiles/app.dir/logic.cpp.i

CMakeFiles/app.dir/logic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/logic.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/logic.cpp -o CMakeFiles/app.dir/logic.cpp.s

CMakeFiles/app.dir/output.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/output.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/output.cpp
CMakeFiles/app.dir/output.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/app.dir/output.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/output.cpp.o -MF CMakeFiles/app.dir/output.cpp.o.d -o CMakeFiles/app.dir/output.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/output.cpp

CMakeFiles/app.dir/output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/output.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/output.cpp > CMakeFiles/app.dir/output.cpp.i

CMakeFiles/app.dir/output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/output.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/output.cpp -o CMakeFiles/app.dir/output.cpp.s

CMakeFiles/app.dir/search_sort.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/search_sort.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/search_sort.cpp
CMakeFiles/app.dir/search_sort.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/app.dir/search_sort.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/search_sort.cpp.o -MF CMakeFiles/app.dir/search_sort.cpp.o.d -o CMakeFiles/app.dir/search_sort.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/search_sort.cpp

CMakeFiles/app.dir/search_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/search_sort.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/search_sort.cpp > CMakeFiles/app.dir/search_sort.cpp.i

CMakeFiles/app.dir/search_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/search_sort.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/search_sort.cpp -o CMakeFiles/app.dir/search_sort.cpp.s

CMakeFiles/app.dir/string_utils.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/string_utils.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/string_utils.cpp
CMakeFiles/app.dir/string_utils.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/app.dir/string_utils.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/string_utils.cpp.o -MF CMakeFiles/app.dir/string_utils.cpp.o.d -o CMakeFiles/app.dir/string_utils.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/string_utils.cpp

CMakeFiles/app.dir/string_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/string_utils.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/string_utils.cpp > CMakeFiles/app.dir/string_utils.cpp.i

CMakeFiles/app.dir/string_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/string_utils.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/string_utils.cpp -o CMakeFiles/app.dir/string_utils.cpp.s

CMakeFiles/app.dir/struct_input.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/struct_input.cpp.o: /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/struct_input.cpp
CMakeFiles/app.dir/struct_input.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/app.dir/struct_input.cpp.o"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/struct_input.cpp.o -MF CMakeFiles/app.dir/struct_input.cpp.o.d -o CMakeFiles/app.dir/struct_input.cpp.o -c /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/struct_input.cpp

CMakeFiles/app.dir/struct_input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/struct_input.cpp.i"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/struct_input.cpp > CMakeFiles/app.dir/struct_input.cpp.i

CMakeFiles/app.dir/struct_input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/struct_input.cpp.s"
	/usr/bin/clang++-18 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/struct_input.cpp -o CMakeFiles/app.dir/struct_input.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/main.cpp.o" \
"CMakeFiles/app.dir/array_utils.cpp.o" \
"CMakeFiles/app.dir/input.cpp.o" \
"CMakeFiles/app.dir/logic.cpp.o" \
"CMakeFiles/app.dir/output.cpp.o" \
"CMakeFiles/app.dir/search_sort.cpp.o" \
"CMakeFiles/app.dir/string_utils.cpp.o" \
"CMakeFiles/app.dir/struct_input.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/main.cpp.o
app: CMakeFiles/app.dir/array_utils.cpp.o
app: CMakeFiles/app.dir/input.cpp.o
app: CMakeFiles/app.dir/logic.cpp.o
app: CMakeFiles/app.dir/output.cpp.o
app: CMakeFiles/app.dir/search_sort.cpp.o
app: CMakeFiles/app.dir/string_utils.cpp.o
app: CMakeFiles/app.dir/struct_input.cpp.o
app: CMakeFiles/app.dir/build.make
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Documents/453502/ОАиП/LabWork_8/Task_1 /home/user/Documents/453502/ОАиП/LabWork_8/Task_1 /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build /home/user/Documents/453502/ОАиП/LabWork_8/Task_1/build/CMakeFiles/app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/app.dir/depend

