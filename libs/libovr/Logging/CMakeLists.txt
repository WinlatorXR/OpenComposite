# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

file(GLOB_RECURSE _srcs
  Logging/*.h
  src/*.cpp
)

add_library(PC_SDK_Logging STATIC ${_srcs})

target_include_directories(PC_SDK_Logging PUBLIC .)
