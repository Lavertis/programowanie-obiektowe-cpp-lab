project(google_test)

#include_directories(../)
add_subdirectory(../googletest-release-1.11.0 googletest)

add_executable(google_test_run isPrime_test.cpp)
target_link_libraries(google_test_run gtest gtest_main)