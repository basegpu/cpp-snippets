#include <gtest/gtest.h>
#include "swapping.hpp"

using namespace pointers;

class PointerTest :
    public ::testing::Test
{
protected:
	int i1;
	int i2;
	Data d;

	void SetUp() override
	{
		this->i1 = 1;
		this->i2 = 2;
		d = Data(&this->i1, &this->i2);
	}
};

TEST_F(PointerTest, WithoutSwapping)
{
    ASSERT_EQ(i2, *this->d.GetTplus1());
}

TEST_F(PointerTest, WithSwapping)
{
	this->d.Swap();
    ASSERT_EQ(i1, *this->d.GetTplus1());
}
