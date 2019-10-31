#include <gtest/gtest.h>
#include "swapping.hpp"

using namespace pointers;


TEST(PointerTests, First)
{
	int i1 = 1, i2 = 2;
	Data(&i1, &i2);
    //ASSERT_DOUBLE_EQ(2.0, loop(f, Methods::Regular, 1e5));
}