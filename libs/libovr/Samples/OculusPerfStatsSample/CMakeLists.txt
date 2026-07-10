# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

file(GLOB _srcs
  OculusPerfStatsSample.cpp
)

add_executable(OculusPerfStatsSample ${_srcs})

target_link_libraries(OculusPerfStatsSample PUBLIC LibOVR)
