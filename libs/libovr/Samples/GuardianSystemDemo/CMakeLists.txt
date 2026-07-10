# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

file(GLOB _srcs
  main.cpp
)

add_executable(GuardianSystemDemo WIN32 ${_srcs})

target_link_libraries(GuardianSystemDemo PUBLIC LibOVR)
