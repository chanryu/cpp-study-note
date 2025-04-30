add_executable(range_tests test.cpp)
target_link_libraries(range_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(range_tests)
