# Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

cmake_minimum_required(VERSION 3.7)

find_package(Vulkan)
file(GLOB _vulkan_sdk_directories $ENV{VULKAN_SDK}/*)
find_program(GLSLANG_VALIDATOR NAMES glslangValidator PATHS _vulkan_sdk_directories)

if(Vulkan_FOUND AND GLSLANG_VALIDATOR)
  file(GLOB _srcs
    main.cpp
    ort.rc
    ort.vert
    ort.frag
    ../Common/Win32_VulkanAppUtil.h
  )

  add_executable(OculusRoomTiny_Vk WIN32 ${_srcs})

  add_custom_command(COMMENT "Compiling ort.vert"
                    OUTPUT ort.vert.spv
                    COMMAND ${GLSLANG_VALIDATOR} -V -o ${CMAKE_CURRENT_BINARY_DIR}/ort.vert.spv ${CMAKE_CURRENT_SOURCE_DIR}/ort.vert
                    MAIN_DEPENDENCY ort.vert
                    DEPENDS ort.vert ${GLSLANG_VALIDATOR})

  add_custom_command(COMMENT "Compiling ort.frag"
                    OUTPUT ort.frag.spv
                    COMMAND ${GLSLANG_VALIDATOR} -V -o ${CMAKE_CURRENT_BINARY_DIR}/ort.frag.spv ${CMAKE_CURRENT_SOURCE_DIR}/ort.frag
                    MAIN_DEPENDENCY ort.frag
                    DEPENDS ort.frag ${GLSLANG_VALIDATOR})

  include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

  target_link_libraries(OculusRoomTiny_Vk
    PUBLIC
      LibOVR
      Vulkan::Vulkan
  )
endif()
