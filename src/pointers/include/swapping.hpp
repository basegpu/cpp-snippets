#pragma once

#include <algorithm>

namespace pointers
{
    typedef struct Data
    {
        Data() : T_(nullptr), Tplus1_(nullptr) {}
        Data(int* T, int* Tp1) : T_(T), Tplus1_(Tp1) {}
        int* GetTplus1()
        {
            return this->Tplus1_;
        }
        void Swap()
        {
            std::swap(this->T_, this->Tplus1_);
        }
    private:
        int* T_;
        int* Tplus1_;
    } Data;
}
