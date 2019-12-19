#include <gtest/gtest.h>
#include "ostreamredirection.hpp"

using namespace redirect;

class RedirectTest :
    public ::testing::Test
{
protected:
	std::ostringstream oss_;
	OStreamRedirection* sr_;

	void SetUp() override
	{
		this->sr_ = new OStreamRedirection(std::cout, this->oss_);
	}
};

TEST_F(RedirectTest, OStream)
{
	const std::string str = "should be captured";
	std::cout << str;
	delete this->sr_;
	std::cout << "on console" << std::endl;
    ASSERT_EQ(str, this->oss_.str());
}
