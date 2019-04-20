cmake_minimum_required (VERSION 3.0)
project ( Third_Task )

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_executable( Second_Task Second_Task.cpp functions.h functions.cpp UI.h UI.cpp studentClass.h studentClass.cpp timerClass.h)