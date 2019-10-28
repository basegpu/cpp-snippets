#pragma once

#include <unordered_map>
#include <map>
#include <armadillo>
#include "variant.hpp"

namespace container
{
    template<class K>
    class Container : private std::map<K, Variant_t>
    {
    public:
        ~Container()
        {
            for (auto kv : *this)
            {
                delete kv.second;
            }
        }

        template<typename T>
        void AddItem(const K& label, const int& nRows, const int& nCols)
        {
            this->operator[](label) = Variant::Create<T>(nRows, nCols);
        }
        
        int GetSize()
        {
            return this->size();
        }
        
        Variant_t GetItem(const K& label)
        {
            if (this->count(label) == 0)
            {
                throw std::out_of_range("no item found.");
            }
            return this->at(label);
        }

        template<typename T>
        arma::Mat<T>* GetDataFrom(const K& label)
        {
            auto v = this->GetItem(label);
            return v->template Get<T>();
        }
    };
}
