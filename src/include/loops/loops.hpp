#pragma once

#include <functional>
#include <string>

namespace loops
{
    typedef std::function<double(const int&)> func;
    typedef std::function<double(func)> method;

    double runJob(
        const func& f,
        const int& n,
        const std::string& msg,
        const method& m);

    enum class Methods : int {
    	Regular,
    	Recursion,
    	Templated
    };

    double loop(const func&, const Methods& m, const int& nReps);
}
