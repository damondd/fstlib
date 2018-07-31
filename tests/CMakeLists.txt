aux_source_directory(gtest/src GTEST_SRCS)
add_library(gtest STATIC ${GTEST_SRCS})
target_include_directories(gtest PUBLIC
  gtest
  gtest/include
  gtest/include/internal)

aux_source_directory(fstlibtests FSTLIBTESTS_SRCS)
add_executable(fstlibtest ${FSTLIBTESTS_SRCS})
target_include_directories(fstlibtest PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(fstlibtest PRIVATE
  fst
  gtest)

