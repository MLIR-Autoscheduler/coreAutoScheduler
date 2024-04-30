

cmake_minimum_required(VERSION 3.13.4)

# Define the project and its properties
project(coreAutoScheduler LANGUAGES CXX C)

# Add the include directories
include_directories(include)

# Add the source files
file(GLOB SOURCES "src/*.cpp")

# Add the library
add_library(coreAutoScheduler STATIC ${SOURCES})
