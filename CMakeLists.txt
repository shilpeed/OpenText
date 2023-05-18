cmake_minimum_required(VERSION 3.12)
project(XMLtoHTML CXX)

set(CMAKE_CXX_STANDARD 14)

# Add the libxml2 library
find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR})

# Add the executable target
add_executable(XMLtoHTML xml_to_html.cpp)
target_link_libraries(XMLtoHTML ${LIBXML2_LIBRARIES})

# Set the output directory for the executable
set_target_properties(XMLtoHTML PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define a custom target to run the executable with command line arguments
add_custom_target(run
    COMMAND XMLtoHTML cd_catalog.xml output.html
    DEPENDS XMLtoHTML
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
