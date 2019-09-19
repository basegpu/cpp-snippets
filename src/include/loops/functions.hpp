#pragma once

#define Nsum 1<<8

namespace loops
{
    double sumLoop(const func& f)
    {
        double sum = 0.0;
        for (int ii = 0; ii <= Nsum; ii++)
        {
            sum += f(ii);
        }
        return sum;
    }

    double doRecursion(const func& f, const int& x)
    {
        if (x != 0)
        {
            return f(x) + doRecursion(f, x - 1);
        }
        else
        {
            return f(x);
        }
    }

    double recursion(const func& f)
    {
        return doRecursion(f, Nsum);
    }

    template<int N>
    double doRecursion(const func& f)
    {
        return f(N) + doRecursion<N-1>(f);
    }

    template<>
    double doRecursion<0>(const func& f)
    {
        return f(0);
    }

    double templated(const func& f)
    {
        return doRecursion<Nsum>(f);
    }
}
