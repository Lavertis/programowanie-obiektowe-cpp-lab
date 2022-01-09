project(google_test)

add_subdirectory(googletest-release-1.11.0 googletest)

add_executable(google_test_run example/FunctionsTests.cpp ../example/functions.cpp ../example/Number.cpp example/NumberClassTests.cpp task_1_tests.cpp task_2_tests.cpp ../task_3/BankAccount.cpp task_3_tests.cpp)
target_link_libraries(google_test_run gtest gtest_main gmock)