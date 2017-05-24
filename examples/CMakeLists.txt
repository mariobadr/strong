if(STRONG_BUILD_EXAMPLES)
  add_executable(comp-arch computer_architecture.cpp)

  target_link_libraries(comp-arch strong)

  set_target_properties(
    comp-arch PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
  )
endif()
