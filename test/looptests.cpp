#include <gtest/gtest.h>
#include "loops.hpp"
#include <cmath>
#include <stdexcept>

using namespace loops;

// function to be evaluated
func f = [](const int& x)
{
    return 1.0 * std::pow(0.5, x);
};

TEST(LoopTests, RegularLoop)
{
    ASSERT_DOUBLE_EQ(2.0, loop(f, Methods::Regular, 1e5));
}

TEST(LoopTests, RecursionLoop)
{
    ASSERT_DOUBLE_EQ(2.0, loop(f, Methods::Recursion, 1e5));
}

TEST(LoopTests, TemplatedLoop)
{
   ASSERT_DOUBLE_EQ(2.0, loop(f, Methods::Templated, 1e5));
}

TEST(LoopTests, BadMethod)
{
    ASSERT_THROW(
        loop(f, (Methods)3, 1e5),
        std::invalid_argument);
}