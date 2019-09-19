#include "loops/loops.hpp"
#include "loops/functions.hpp"

#include <cstdio>
#include <ctime>
#include <string>

namespace loops
{
    double runJob(
        const func& f,
        const int& n,
        const std::string& msg,
        const method& m)
    {
        double out;
        auto start = std::clock();
        for (int ii = 0; ii < n; ii++)
        {
            out = m(f);
        }
        auto end = std::clock();
        std::printf(
            "%s (%1.9f): %1.6f ms\n",
            msg.c_str(),
            out,
            1000.0 * (end-start) / CLOCKS_PER_SEC / n
        );
        return out;
    }

    double loop(const func& f, const Methods& method, const int& nReps)
    {
        switch (int(method))
        {
            case 0: return runJob(f, nReps, "regular for loop", sumLoop);
            case 1: return runJob(f, nReps, "recursion", recursion);
            case 2: return runJob(f, nReps, "templated", templated);
        }
    }
}
