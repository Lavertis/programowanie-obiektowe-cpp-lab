#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "../../example/functions.h"

using namespace testing;

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
// Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(IsEvenTest, OddTests) {
    ASSERT_EQ(false, isEven(5));
}

TEST(IsEvenTest, EvenTests) {
    ASSERT_NE(false, isEven(6));
}

TEST(SignTest, FirstIfTests) {
    ASSERT_THAT(1, Eq(sign(6)));
}

TEST(DifferenceTest, OkResultTests) {
    std::vector<int> res;
    std::vector<int> num{1, 2, 3, 6, 5};
    res = difference(num);
    std::vector<int> resExpected{1, 1, 3, -1};
    ASSERT_EQ(res.size(), resExpected.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i], resExpected[i]) << " Iteration: " << i << std::endl;
    }
}

TEST(ShowTest, EmptyLineTests) {
    EXPECT_THROW(show(""), std::runtime_error);
}

TEST(IsEvenTest, OddTestsErr) {
    ASSERT_EQ(true, isEven(5));
}

TEST(DifferenceTest, OkResultTestsErr) {
    std::vector<int> res;
    std::vector<int> num{1, 2, 3, 6, 5};
    res = difference(num);
    std::vector<int> resExpected{1, 2, 3, 6, 5};
    ASSERT_EQ(res.size(), resExpected.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i], resExpected[i]) << " Iteration: " << i << std::endl;
    }
}
