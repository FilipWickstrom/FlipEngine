# Welcome to FlipEngine
A hobby 3D-engine with main focus on Direct3D (11) for now. Here I will learn new techniques and programming in general with main focus in 3D-rendering.

# Tested platforms
| OS        | Version   | Compilation using   |
|-----------|-----------|---------------------|
| Windows   | 10        | Visual Studio 2022  |
| Linux     | Ubuntu    | GNU makefiles       |


# How to download
You can download it using Git with the command:

> git clone https://github.com/FilipWickstrom/FlipEngine.git
<!-- 
    git clone https://github.com/FilipWickstrom/FlipEngine.git --recurse-submodules --remote-submodules 
    This will download all the 3rd-party libraries that are needed to build the project. 
-->
or 
> Download as Zip on GitHub [here](https://github.com/FilipWickstrom/FlipEngine/archive/refs/heads/main.zip)

# Build project
1. Go into the folder called "ProjectBuild" and choose platform "Windows" or "Linux".
2. Build the solution/makefile with one of the files using the version most fitted for your need.
3. Open solution for Visual Studio in main directory.

# Libraries and 3rd-parties
* [GLFW (3.3)](https://irrlicht.sourceforge.io/) Creates the window and handle input.
* [spdlog (1.11)](https://github.com/gabime/spdlog) Very fast logging library.
