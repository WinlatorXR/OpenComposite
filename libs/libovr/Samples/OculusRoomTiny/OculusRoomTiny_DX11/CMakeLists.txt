# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

file(GLOB _srcs main.cpp)

add_executable(OculusRoomTiny_DX11 WIN32 ${_srcs})

target_link_libraries(OculusRoomTiny_DX11
  PUBLIC
    LibOVR
)
