@echo off

REM Create a build directory
mkdir build
cd build

REM Run CMake to generate build files
cmake ..

REM Build the project
cmake --build .

REM Run the executable with command line arguments
XMLtoHTML.exe cd_catalog.xml output.html
