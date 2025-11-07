

### cmake for data structure package ###

# default stuff
cmake_minimum_required(VERSION 3.22)

project(
    data_structures
    VERSION 1.0.0
    LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

# variables
set(INCLUDE_DIRECTORY
    "include"
)

# enable/disable certain parts of compilation
option(RUN_TESTS "enable tests" ON)

# external libraries
# Test library
if (RUN_TESTS)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/6ec14dfd8c409d05fba94e18e3a02df35b874353.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
endif()

# external cmake files
add_subdirectory(main)
add_subdirectory(src)
if (RUN_TESTS)
    add_subdirectory(tests)
endif()


