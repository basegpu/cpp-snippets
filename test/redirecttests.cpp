#include <gtest/gtest.h>
#include "ostreamredirection.hpp"
#include "coutcollector.hpp"

using namespace redirect;

const std::string str_out = "should be captured";

TEST(RedirectTest, OStreamRedirection)
{
	std::ostringstream oss;
	OStreamRedirection* sr = new OStreamRedirection(std::cout, oss);

	std::cout << str_out;
	delete sr;

	std::cout << "on console" << std::endl;
    
    ASSERT_EQ(str_out, oss.str());
}

TEST(RedirectTest, CoutCollector)
{
	{
		CoutCollector logger;
		std::cout << str_out;
		ASSERT_EQ(str_out, logger.GetContent());
	}

	std::cout << "on console" << std::endl;
}
