#include <gtest/gtest.h>
#include "scopedredirect.hpp"

using namespace redirect;

class RedirectTest :
    public ::testing::Test
{
protected:
	std::ostringstream oss_;
	ScopedRedirect* sr_;

	void SetUp() override
	{
		this->sr_ = new ScopedRedirect(std::cout, this->oss_);
	}
};

TEST_F(RedirectTest, Dummy)
{
	const std::string str = "should be captured";
	std::cout << str;
	delete this->sr_;
	std::cout << "on console" << std::endl;
    ASSERT_EQ(str, this->oss_.str());
}
