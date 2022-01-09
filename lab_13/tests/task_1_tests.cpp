#include <gtest/gtest.h>
#include "../task_1.h"

TEST(isPrimeFunc, DefaultTest) {
    ASSERT_FALSE(isPrime(-10));
    ASSERT_FALSE(isPrime(1));
    ASSERT_TRUE(isPrime(2));
    ASSERT_FALSE(isPrime(4));
    ASSERT_FALSE(isPrime(36));
    ASSERT_TRUE(isPrime(37));
}