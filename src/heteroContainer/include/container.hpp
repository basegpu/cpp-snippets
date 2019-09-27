#pragma once

#include <unordered_map>
#include <armadillo>
#include <string>
#include "variant.hpp"

namespace container
{
    class Container : private std::unordered_map<std::string, Variant_t>
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

        template<typename T>
        arma::Mat<T>* GetDataFrom(const std::string& label)
        {
            return this->GetItem(label)->Get<T>();
        }
    };
}
