cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(
  strong
  VERSION 0.2.0.0
  LANGUAGES CXX
  )

# Potential build options
option(
  STRONG_BUILD_DOCS
  "Create HTML/PDF documentation (requires Doxygen)"
  OFF
)

option(
  STRONG_USE_STL_STREAMS
  "Include and use the std::ostream and std::istream for stream operations"
  ON
)

# Header-only library
add_library(${PROJECT_NAME} INTERFACE)

target_sources(
  ${PROJECT_NAME}
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/strong.hpp
)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE include
)

if(STRONG_USE_STL_STREAMS)
  target_compile_definitions(
    ${PROJECT_NAME} INTERFACE
    STRONG_USE_STL_STREAMS=1
  )
endif()

install(
  FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/strong.hpp
  DESTINATION include
)

# Documentation
add_subdirectory(doc)

# Examples
add_subdirectory(examples)
