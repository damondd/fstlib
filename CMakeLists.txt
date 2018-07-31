cmake_minimum_required(VERSION 3.5.1)
project(fstlib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
add_compile_options("$<$<CONFIG:Release>:-O3>")
add_compile_options("$<$<CONFIG:Debug>:-g;-O0>")
add_compile_options(-Wall -Wextra)

find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

add_subdirectory(fstlib)
add_subdirectory(tests)

#install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#  DESTINATION include/fstlib
#  FILES_MATCHING PATTERN "*.h")

