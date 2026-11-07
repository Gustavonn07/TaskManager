add_library(UtilsLib
  Logger.cpp
)

target_include_directories(UtilsLib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(UtilsLib PUBLIC cxx_std_20)
