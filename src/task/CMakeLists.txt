add_library(TaskLib
  Task.cpp
  TaskManager.cpp
)

target_include_directories(TaskLib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(TaskLib PUBLIC cxx_std_20)
