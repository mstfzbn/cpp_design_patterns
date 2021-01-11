cmake_minimum_required(VERSION 3.7)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(first)

add_executable(

  first
  includes.h
  prototype.h
  singleton.h
  builder.h
  main.cpp
)
