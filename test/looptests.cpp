#include <gtest/gtest.h>
#include "loops/loops.hpp"
#include <cmath>
#include <stdexcept>

// function to be evaluated
loops::func f = [](const int& x)
{
    return 1.0 * std::pow(0.5, x);
};

TEST(LoopTests, RegularLoop)
{
    ASSERT_DOUBLE_EQ(2.0, loops::loop(f, loops::Methods::Regular, 1e5));
}

TEST(LoopTests, RecursionLoop)
{
    ASSERT_DOUBLE_EQ(2.0, loops::loop(f, loops::Methods::Recursion, 1e5));
}

TEST(LoopTests, TemplatedLoop)
{
   ASSERT_DOUBLE_EQ(2.0, loops::loop(f, loops::Methods::Templated, 1e5));
}

TEST(LoopTests, BadMethod)
{
    ASSERT_THROW(
        loops::loop(f, (loops::Methods)3, 1e5),
        std::invalid_argument);
}