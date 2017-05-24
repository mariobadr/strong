option(
  STRONG_BUILD_DOCS
  "Create HTML/PDF documentation (requires Doxygen)"
  OFF
)

option(
  STRONG_BUILD_EXAMPLES
  "Build the example executables that use strong"
  OFF
)

option(
  STRONG_USE_STL_STREAMS
  "Include and use the std::ostream and std::istream for stream operations"
  ON
)

if(STRONG_BUILD_DOCS)
  message(STATUS "strong: doc target builds documentation.")
endif()

if(STRONG_BUILD_EXAMPLES)
  message(STATUS "strong: Example executables will be built.")
endif()

if(STRONG_USE_STL_STREAMS)
  message(STATUS "strong: Using STL streams.")
endif()
