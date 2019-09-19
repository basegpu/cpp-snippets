#include <gtest/gtest.h>
#include "loops/loops.hpp"
#include <cmath>

loops::func f = [](const int& x)
{
    return 1.0 * std::pow(0.5, x);
};

TEST(LoopTests, RegularLoop)
{
    // function to be evaluated
    ASSERT_DOUBLE_EQ(2.0, loops::loop(f, loops::Methods::Regular, 1e5));
}

TEST(LoopTests, RecursionLoop)
{
    // function to be evaluated
    ASSERT_DOUBLE_EQ(2.0, loops::loop(f, loops::Methods::Recursion, 1e5));
}

TEST(LoopTests, TemplatedLoop)
{
    // function to be evaluated
    ASSERT_DOUBLE_EQ(2.0, loops::loop(f, loops::Methods::Templated, 1e5));
}