add_library(Task
  Task.cpp
)

target_include_directories(Task PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(Task PUBLIC cxx_std_20)

target_link_libraries(TaskManager PRIVATE
  TaskLib
)