#include <gtest/gtest.h>
#include "scopedredirect.hpp"

using namespace redirect;

class RedirectTest :
    public ::testing::Test
{
protected:

	void SetUp() override
	{
	}
};

TEST_F(RedirectTest, Dummy)
{
	ScopedRedirect::Test();
    ASSERT_EQ(1, 1);
}
