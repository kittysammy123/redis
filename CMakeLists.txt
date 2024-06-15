cmake_minimum_required(VERSION  3.16)


project(redis VERSION 1.0.0)


set(CMAKE_CXX_STANDARD  17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)


add_subdirectory(test)