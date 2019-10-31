#include <gtest/gtest.h>
#include "swapping.hpp"

using namespace pointers;


TEST(PointerTests, WithoutSwapping)
{
	int i1 = 1, i2 = 2;
	auto d = Data(&i1, &i2);
    ASSERT_EQ(i1, *d.GetT());
    ASSERT_EQ(i2, *d.GetTplus1());
}

TEST(PointerTests, WithSwapping)
{
	int i1 = 1, i2 = 2;
	auto d = Data(&i1, &i2);
	d.Swap();
    ASSERT_EQ(i2, *d.GetT());
    ASSERT_EQ(i1, *d.GetTplus1());
}