# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build

# Include any dependencies generated for this target.
include CMakeFiles/projet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projet.dir/flags.make

CMakeFiles/projet.dir/srcs/main.c.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/srcs/main.c.o: ../srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projet.dir/srcs/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projet.dir/srcs/main.c.o   -c /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/main.c

CMakeFiles/projet.dir/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet.dir/srcs/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/main.c > CMakeFiles/projet.dir/srcs/main.c.i

CMakeFiles/projet.dir/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet.dir/srcs/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/main.c -o CMakeFiles/projet.dir/srcs/main.c.s

CMakeFiles/projet.dir/srcs/main_menu.c.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/srcs/main_menu.c.o: ../srcs/main_menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projet.dir/srcs/main_menu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projet.dir/srcs/main_menu.c.o   -c /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/main_menu.c

CMakeFiles/projet.dir/srcs/main_menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet.dir/srcs/main_menu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/main_menu.c > CMakeFiles/projet.dir/srcs/main_menu.c.i

CMakeFiles/projet.dir/srcs/main_menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet.dir/srcs/main_menu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/main_menu.c -o CMakeFiles/projet.dir/srcs/main_menu.c.s

CMakeFiles/projet.dir/srcs/game.c.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/srcs/game.c.o: ../srcs/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/projet.dir/srcs/game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projet.dir/srcs/game.c.o   -c /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/game.c

CMakeFiles/projet.dir/srcs/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet.dir/srcs/game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/game.c > CMakeFiles/projet.dir/srcs/game.c.i

CMakeFiles/projet.dir/srcs/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet.dir/srcs/game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/game.c -o CMakeFiles/projet.dir/srcs/game.c.s

CMakeFiles/projet.dir/srcs/screen.c.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/srcs/screen.c.o: ../srcs/screen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/projet.dir/srcs/screen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projet.dir/srcs/screen.c.o   -c /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/screen.c

CMakeFiles/projet.dir/srcs/screen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet.dir/srcs/screen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/screen.c > CMakeFiles/projet.dir/srcs/screen.c.i

CMakeFiles/projet.dir/srcs/screen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet.dir/srcs/screen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/screen.c -o CMakeFiles/projet.dir/srcs/screen.c.s

CMakeFiles/projet.dir/srcs/game_screen.c.o: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/srcs/game_screen.c.o: ../srcs/game_screen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/projet.dir/srcs/game_screen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projet.dir/srcs/game_screen.c.o   -c /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/game_screen.c

CMakeFiles/projet.dir/srcs/game_screen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet.dir/srcs/game_screen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/game_screen.c > CMakeFiles/projet.dir/srcs/game_screen.c.i

CMakeFiles/projet.dir/srcs/game_screen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet.dir/srcs/game_screen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/srcs/game_screen.c -o CMakeFiles/projet.dir/srcs/game_screen.c.s

# Object files for target projet
projet_OBJECTS = \
"CMakeFiles/projet.dir/srcs/main.c.o" \
"CMakeFiles/projet.dir/srcs/main_menu.c.o" \
"CMakeFiles/projet.dir/srcs/game.c.o" \
"CMakeFiles/projet.dir/srcs/screen.c.o" \
"CMakeFiles/projet.dir/srcs/game_screen.c.o"

# External object files for target projet
projet_EXTERNAL_OBJECTS =

projet: CMakeFiles/projet.dir/srcs/main.c.o
projet: CMakeFiles/projet.dir/srcs/main_menu.c.o
projet: CMakeFiles/projet.dir/srcs/game.c.o
projet: CMakeFiles/projet.dir/srcs/screen.c.o
projet: CMakeFiles/projet.dir/srcs/game_screen.c.o
projet: CMakeFiles/projet.dir/build.make
projet: /usr/lib64/libSDL2.so
projet: /usr/lib64/libSDL2_image.so
projet: /usr/lib64/libSDL2_ttf.so
projet: CMakeFiles/projet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable projet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projet.dir/build: projet

.PHONY : CMakeFiles/projet.dir/build

CMakeFiles/projet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projet.dir/clean

CMakeFiles/projet.dir/depend:
	cd /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build /media/psf/Home/Documents/ESIEA/Info_Projects/PROJET_C_ESIEA_1A/bonus/build/CMakeFiles/projet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projet.dir/depend

