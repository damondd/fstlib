aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} FSTLIB_SRCS)
aux_source_directory(fstcore/blockstreamer FSTLIB_SRCS)
aux_source_directory(fstcore/byte FSTLIB_SRCS)
aux_source_directory(fstcore/character FSTLIB_SRCS)
aux_source_directory(fstcore/compression FSTLIB_SRCS)
aux_source_directory(fstcore/double FSTLIB_SRCS)
aux_source_directory(fstcore/factor FSTLIB_SRCS)
aux_source_directory(fstcore/integer FSTLIB_SRCS)
aux_source_directory(fstcore/integer64 FSTLIB_SRCS)
aux_source_directory(fstcore/interface FSTLIB_SRCS)
aux_source_directory(fstcore/logical FSTLIB_SRCS)
aux_source_directory(fstcore/LZ4 FSTLIB_SRCS)
aux_source_directory(fstcore/ZSTD/common FSTLIB_SRCS)
aux_source_directory(fstcore/ZSTD/compress FSTLIB_SRCS)
aux_source_directory(fstcore/ZSTD/decompress FSTLIB_SRCS)
aux_source_directory(fstcore/ZSTD/dictBuilder FSTLIB_SRCS)

add_library(fst SHARED ${FSTLIB_SRCS})
target_include_directories(fst PUBLIC
  ${CMAKE_SOURCE_DIR}
  fstcore/LZ4
  fstcore/ZSTD
  fstcore/ZSTD/common)

install(TARGETS fst
  LIBRARY  DESTINATION lib)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DESTINATION include
  FILES_MATCHING PATTERN "*.h")

