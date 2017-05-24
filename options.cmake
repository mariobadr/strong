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

if(STRONG_BUILD_DOCS)
  message(STATUS "strong: Documentation option enabled.")
endif()

if(STRONG_USE_STL_STREAMS)
  message(STATUS "strong: Using STL streams.")
endif()
