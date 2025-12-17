cmake_minimum_required(VERSION 3.16)
project(backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/workflow
    ${CMAKE_CURRENT_SOURCE_DIR}/services
    ${CMAKE_CURRENT_SOURCE_DIR}/storage
)

# Source files (adjust if needed)
file(GLOB BACKEND_SOURCES
    utils/*.cpp
    workflow/*.cpp
    services/*.cpp
    storage/*.cpp
    app.cpp
)

# Build backend as a library for testing
add_library(backend_lib STATIC ${BACKEND_SOURCES})

# Build main application
add_executable(backend_app main.cpp)
target_link_libraries(backend_app PRIVATE backend_lib)
