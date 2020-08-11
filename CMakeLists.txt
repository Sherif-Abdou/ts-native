cmake_minimum_required(VERSION 3.17)
project(typescript_native)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_PATH  ${CMAKE_LIBRARY_PATH} "/Users/sherif/.boost/include")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/Users/sherif/.boost/lib")

include_directories(${BOOST_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(test)