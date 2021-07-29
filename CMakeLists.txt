cmake_minimum_required(VERSION 3.16.3)

project(sdl-renderer-2d)

set(CMAKE_CXX_STANDARD 17)
if(!MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(!MSVC)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
set(SDL2_PATH "${CMAKE_SOURCE_DIR}")
set(SDL2_SEARCH_PATHS ${SDL2_PATH})
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIR})
endif() 

include_directories(includes)
link_directories(includes/SDL)

include_directories(configuration)
configure_file(configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)

if(WIN32)
link_directories(lib)
endif()

add_executable(sdl-renderer-2d WIN32 src/Application.cpp)
               
target_link_libraries(sdl-renderer-2d SDL2)

if(WIN32)
add_custom_command(TARGET sdl-renderer-2d POST_BUILD   
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/lib/SDL2.dll"
        $<TARGET_FILE_DIR:sdl-renderer-2d>)    
endif()