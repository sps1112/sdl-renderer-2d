cmake_minimum_required(VERSION 3.16.3)

project(sdl-renderer-2d)

set(CMAKE_CXX_STANDARD 11)
if(!MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++11")
endif(!MSVC)

add_executable(sdl-renderer-2d src/application.cpp)