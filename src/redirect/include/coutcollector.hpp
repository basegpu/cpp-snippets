#pragma once

#include "ostreamredirection.hpp"
#include <iostream>
#include <string>

namespace redirect
{

	class CoutCollector
	{
	public:

		CoutCollector() :
			str_out_("")
		{
			this->osr_ = new OStreamRedirection(std::cout, this->oss_);
		}

		~CoutCollector()
		{
			delete this->osr_;
		}

		const std::string& GetContent()
		{
			this->str_out_ = this->oss_.str();
			return this->str_out_;
		}

	private:
		// local string
		std::string str_out_;
		std::ostringstream oss_;
		OStreamRedirection* osr_;
	};

}