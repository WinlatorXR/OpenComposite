# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

# VS2019 is not happy with std::filesystem::experimental
if(MSVC_VERSION GREATER_EQUAL 1920)
  set(CMAKE_CXX_STANDARD 17)
endif()

file(GLOB _srcs
  *.h
  *.cpp
)

file(GLOB_RECURSE _asset_srcs
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  Assets/*
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(OculusWorldDemo WIN32 ${_srcs})

target_link_libraries(OculusWorldDemo
  PUBLIC
    CommonSrc
    LibOVR
    LibOVRKernel
    TinyXml
)

#
# Copy required assets from source tree to build output
#
foreach(FILENAME ${_asset_srcs})
    add_custom_command(
            TARGET OculusWorldDemo POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
                    ${CMAKE_CURRENT_SOURCE_DIR}/${FILENAME}
                    ${CMAKE_CURRENT_BINARY_DIR}/$(Configuration)/${FILENAME})
endforeach(FILENAME)
