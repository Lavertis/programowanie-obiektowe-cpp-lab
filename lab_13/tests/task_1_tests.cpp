#include <gtest/gtest.h>
#include "../task_1/task_1.h"

TEST(isPrimeFunc, ValuesLessThan2) {
    ASSERT_FALSE(isPrime(-10));
    ASSERT_FALSE(isPrime(-11));
    ASSERT_FALSE(isPrime(1));
}

TEST(isPrimeFunc, StandardValues) {
    ASSERT_TRUE(isPrime(2));
    ASSERT_FALSE(isPrime(36));
    ASSERT_TRUE(isPrime(37));
}

TEST(isPrimeFunc, SquareRoot) {
    ASSERT_FALSE(isPrime(4));
}