# Add Gtest dependency
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

add_executable(
  main_test
  main_test.cc
)

add_executable(
  queue_test
  queue_test.cc
)

find_package(GTest)

target_link_libraries(
  main_test
  GTest::gtest_main
)

target_link_libraries(
  queue_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main_test)
gtest_discover_tests(queue_test)