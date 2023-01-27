cmake_minimum_required(VERSION 3.14)
project(module-01)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 98)
set(This ex00)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(${This} C CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/403a968d3c1e1de1232ba1c1a2775b74b9ea5579.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

set(Headers
    ../Zombie.hpp
)

set(Sources
    ../Zombie.cpp
    ../newZombie.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(exec_tests)
