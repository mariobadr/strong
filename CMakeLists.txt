cmake_minimum_required(VERSION 3.1)

set(STRONG_TYPES "strong-types")
set(STRONG_TYPES_DESCRIPTION "A Library for Strong Typedefs")

project(
  ${STRONG_TYPES}
  VERSION 0.1.0.0
  LANGUAGES CXX
  )

add_library(${STRONG_TYPES} INTERFACE)

target_sources(
  ${STRONG_TYPES}
  INTERFACE include/strong_types.hpp
)

target_include_directories(
  ${STRONG_TYPES}
  INTERFACE include
)

install(
  FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/strong_types.hpp
  DESTINATION include
)

