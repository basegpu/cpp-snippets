#pragma once

#include <map>
#include <string>
#include "variant.hpp"

namespace container
{
    class Container : private std::map<std::string, Variant_t>
    {
    public:
        ~Container();

        template<typename T>
        void AddItem(const std::string& label, const int& nRows, const int& nCols)
        {
            this->operator[](label) = Variant::Create<T>(nRows, nCols);
        }
        
        int GetSize();
        
        Variant_t GetItem(const std::string& label);
    };
}
