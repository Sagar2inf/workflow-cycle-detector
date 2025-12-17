cmake_minimum_required(VERSION 3.16)

project(backend_tests)

# Catch2
include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(catch2)
include(Catch)

# Main project source
add_subdirectory(.. backend_src)

# Test executables
file(GLOB TEST_FILES *.cpp)

add_executable(run_tests ${TEST_FILES})
target_link_libraries(run_tests PRIVATE backend_lib Catch2::Catch2WithMain)

catch_discover_tests(run_tests)
