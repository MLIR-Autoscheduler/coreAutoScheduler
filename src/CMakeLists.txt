project(autoSchedulerInfrastructure)

# Add the source files
file(GLOB SOURCES "*.cpp")

# Add the library
add_library(autoSchedulerInfrastructure ${SOURCES})

# Add the include directories
target_include_directories(autoSchedulerInfrastructure 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)