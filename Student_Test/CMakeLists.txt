cmake_minimum_required(VERSION 3.12.2)

project(Student_Test)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release"
    CACHE STRING "Configuration types" FORCE)

add_executable(Student_Test
  gtest/gtest.h
  test.cpp
)
# Preprocessor definitions
target_compile_definitions(Student_Test PRIVATE
  $<$<CONFIG:Debug>:_UNICODE;X64;_DEBUG;_CONSOLE>
  $<$<CONFIG:Release>:_UNICODE;X64;NDEBUG;_CONSOLE>
)

# Minimal rebuild
if (MSVC)
  target_compile_options(Student_Test PRIVATE
    "$<$<CONFIG:Debug>:/Gm>"
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(Student_Test PRIVATE
    ""
  )
endif ()
