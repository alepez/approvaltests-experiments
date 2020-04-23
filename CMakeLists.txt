cmake_minimum_required(VERSION 3.14)

project(approvaltests-experiments
  VERSION 0.1.1.1
  )

add_subdirectory(cmake/gtest)
add_subdirectory(cmake/approvaltests)
add_subdirectory(cmake/fmt)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(tests
  tests/experiments.cpp
  tests/main.cpp
  )

target_link_libraries(tests
  gmock
  gtest
  fmt::fmt
  ApprovalTests::ApprovalTests
  )

set_property(TARGET tests PROPERTY CXX_STANDARD 20)

enable_testing()

add_test(NAME tests COMMAND tests)
