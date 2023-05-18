XML to HTML Converter

This is a simple command-line tool to convert XML files into HTML tables.

Usage:
1. Clone the repository:
   - Open a terminal or command prompt.
   - Run the following command:
     git clone 
     cd your_repository

2. Build the project:
   - Ensure you have a C++ compiler and CMake installed on your system.
   - Open a terminal or command prompt.
   - Navigate to the project directory (your_repository).
   - Run the following commands:
     mkdir build
     cd build
     cmake ..
     cmake --build .

3. Convert XML to HTML:
   - In the terminal or command prompt, navigate to the 'build' directory.
   - Run the following command:
     ./XMLtoHTML cd_catalog.xml output.html
   - Replace 'cd_catalog.xml' with the path to your XML file and 'output.html' with the desired path for the output HTML file.

Prerequisites:
- C++ compiler
- CMake
- libxml2 library


