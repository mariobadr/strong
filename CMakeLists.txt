cmake_minimum_required(VERSION 3.1)

set(STRONG "strong")
set(STRONG_DESCRIPTION "A Library for Strong (aka Opaque) Typedefs")

project(
  ${STRONG}
  VERSION 0.1.0.0
  LANGUAGES CXX
  )

# Potential build options
option(
  STRONG_BUILD_DOCS
  "Create HTML/PDF documentation (requires Doxygen)"
  OFF
)

# Header-only library
add_library(${STRONG} INTERFACE)

target_sources(
  ${STRONG}
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/strong.hpp
)

target_include_directories(
  ${STRONG}
  INTERFACE include
)

install(
  FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/strong.hpp
  DESTINATION include
)

# Documentation
add_subdirectory(doc)

# Examples
add_subdirectory(examples)
