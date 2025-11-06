

# data_structures
Implementing a few data structures as an exercise

## Project structure
The project is structured in different subfolders.
The final goal would be to be able to include this into other projects.
Since I don't know how this can be done, the project structure may be subject to change.

### main
This directory contains the main file that is the entry point for the default executable.
Tinkering and playing around with the data structures can be done here.

### build
This directory contains everything related to compiling.
Note that this directory is excluded in the gitignore and should always be generated locally.
For more information, see chapter: CMake Guide for this project.

### include
This directory contains all header files.
Including this directory at several points will make different data structures available.

### src
This directory contains the functionality of the data structures.
Each data structure has its own folder.
Header files with private helper functions are also located here.

### tests
This directory contains the unit tests in case someone decides to write them.

## CMake Guide for this project
CMake can be used to build a c project from the ground up.
Since not all developers might be familiar with CMake, here is a quick rundown of the necessary things to work on your own.

### Building an executable with CMake
To build the project, there are three main steps:
1. configuring the project -> this generates the build instructions for the project, and should be done every time the macroscopic project structure changes
2. compiling everything -> this builds the executable, and should be done every time the source code changes
3. running the executable -> this executes the compiled program

A few commands are predefined in the Makefile to streamline the process of obtaining the executable.
They can be executed in the root directory of this project.

- `make fullbuild` deletes the contents of the build directory, and executes steps 1. 2. 3. automatically
- `make rebuild` only executes steps 2. 3.
- `make run` only executes steps 3.
- `make wipe` only wipes the build directory clean

Commands for building a test executable have not been included in the Makefile yet.

### Expanding the project with CMake
New files have to be included in the CMake infrastructure.
This section will give a quick explanation of how to perform basic expansions.

The backbone of CMake are the `CMakeLists.txt` files.
To organize different components, every directory contains its own CMakeLists file.
If there is a new file in the project, it has to be included in the respective CMakeLists file of this folder.
There should be a line along the lines of `set([..]_SOURCES [..])` where all used files are defined in the following lines.
Adding the new file there will include it in the compilation process.


