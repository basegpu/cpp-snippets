#pragma once

#include <algorithm>

namespace pointers
{
    typedef struct Data
    {
        Data(int* T, int* Tp1) : T_(T), Tplus1_(Tp1) {}
        void swap()
        {
            std::swap(T_, Tplus1_);
        }
    private:
        int* T_;
        int* Tplus1_;
    } Data;
}
