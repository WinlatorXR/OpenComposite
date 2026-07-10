# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

project(OCULUSPCSDK C CXX)

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

add_subdirectory(3rdParty/TinyXml)
add_subdirectory(LibOVRKernel)
add_subdirectory(LibOVR)
add_subdirectory(Logging)
add_subdirectory(Samples)
