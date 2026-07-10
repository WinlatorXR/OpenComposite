# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

file(GLOB_RECURSE _srcs
  tinyxml2.cpp
  tinyxml2.h
)

add_library(TinyXml STATIC ${_srcs})

target_include_directories(TinyXml PUBLIC ..)
