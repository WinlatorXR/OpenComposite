# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

file(GLOB_RECURSE _srcs
  Platform/Platform.cpp
  Platform/Win32_Gamepad.cpp
  Platform/Win32_Platform.cpp
  Render/Render_GL_Device.cpp
  Render/Render_GL_Win32_Device.cpp
  Render/Render_LoadTextureDDS.cpp
  Render/Render_LoadTextureTGA.cpp
  Render/Render_Device.cpp
  Render/Render_D3D11_Device.cpp
  Render/Render_XmlSceneLoader.cpp
  Util/OptionMenu.cpp
  Util/RenderProfiler.cpp
  Util/StringHelper.cpp
)

add_library(CommonSrc STATIC ${_srcs})

target_link_libraries(CommonSrc
  PUBLIC
    LibOVRKernel
    TinyXml
)

target_include_directories(CommonSrc PUBLIC .)
