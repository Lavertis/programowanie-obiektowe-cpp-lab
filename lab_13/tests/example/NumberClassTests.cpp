#include <gtest/gtest.h>
#include "../../example/Number.h"

using namespace testing;

struct NumberTest : Test {
    Number *n;

    NumberTest() {
        n = new Number(4);
    }

    ~NumberTest() override {
        delete n;
    }
};

TEST_F(NumberTest, NumberInc) {
    EXPECT_EQ(5, n->inc());
}

TEST_F(NumberTest, NumberGet) {
    EXPECT_EQ(4, n->getN());
}

struct NumberState {
    int nInit;
    int inc;
};

struct NumberParamTest : NumberTest, WithParamInterface<NumberState> {
    NumberParamTest() {
        n->setN(GetParam().nInit);
    }
};

TEST_P(NumberParamTest, NTests) {
    NumberState as = GetParam();
    int inc = n->inc();
    EXPECT_EQ(as.inc, inc);
}

INSTANTIATE_TEST_CASE_P

(Default, NumberParamTest, Values(NumberState{4, 5}, NumberState{3, 4}));
