cmake_minimum_required(VERSION 3.24)
project(blackjack)
set(CMAKE_CXX_STANDARD 20)

include(Utils.cmake)

setup_conan()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  enable_testing()
  include(GoogleTest)
  add_subdirectory(test)
endif()

add_subdirectory(src)
add_subdirectory(app)
