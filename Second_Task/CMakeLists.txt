cmake_minimum_required(VERSION 3.12.2)

project(Second_Task)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release"
    CACHE STRING "Configuration types" FORCE)

add_executable(Second_Task
  src/functions.cpp
  src/functions.h
  src/humanClass.cpp
  src/humanClass.h
  src/randomEngine.h
  src/Second_Task.cpp
  src/studentClass.cpp
  src/studentClass.h
  src/timerClass.h
  src/UI.cpp
  src/UI.h
  src/Vector.h
)
# Preprocessor definitions
target_compile_definitions(Second_Task PRIVATE
  $<$<CONFIG:Debug>:_MBCS;_DEBUG;_CONSOLE>
  $<$<CONFIG:Release>:_UNICODE;NDEBUG;_CONSOLE>
)

# SDL check
target_compile_options(Second_Task PRIVATE
  "$<$<CONFIG:Debug>:/sdl>"
  "$<$<CONFIG:Release>:/sdl>"
)

# Minimal rebuild
if (MSVC)
  target_compile_options(Second_Task PRIVATE
    "$<$<CONFIG:Debug>:/Gm->"
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(Second_Task PRIVATE
    ""
  )
endif ()
