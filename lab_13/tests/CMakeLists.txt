project(google_test)

#include_directories(../)
add_subdirectory(../googletest-release-1.11.0 googletest)

add_executable(google_test_run example/FunctionsTests.cpp ../example/functions.h ../example/functions.cpp ../example/Number.h ../example/Number.cpp example/NumberClassTests.cpp)
target_link_libraries(google_test_run gtest gtest_main gmock)