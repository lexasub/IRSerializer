cmake_minimum_required(VERSION 3.26)
project(XmlRepo)

set(CMAKE_CXX_STANDARD 23)
aux_source_directory(. DIR_SRCS)

# Add Tinyxml subdirectory
add_subdirectory(tinyXml)

add_executable(XmlRepo main.cpp)
target_link_libraries(XmlRepo tinyxml2)

