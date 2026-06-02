cmake_minimum_required(VERSION 3.5...4.0)
project(ODE)
set(CMAKE_CXX_STANDARD 20)
include(cmake/Dependencies.cmake)
include(cmake/Options.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()

add_subdirectory(src)
