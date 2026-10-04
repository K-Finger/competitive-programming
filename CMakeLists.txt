cmake_minimum_required(VERSION 3.20)

project(CodeforcesPractice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CPP_FILES CONFIGURE_DEPENDS "*.cpp")

foreach(file ${CPP_FILES})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
endforeach()
