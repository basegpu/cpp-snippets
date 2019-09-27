#include <armadillo>
#include <exception>
#include "variant.hpp"

namespace container
{
    Variant::Variant(arma::Mat<double>* const obj) :
        obj_i(nullptr),
        obj_f(obj)
    {
        ;
    }

    Variant::Variant(arma::Mat<int>* const obj) :
        obj_i(obj),
        obj_f(nullptr)
    {
        ;
    }
    
    Variant::~Variant()
    {
        if (this->obj_i)
        {
            delete this->obj_i;
        }
        if (this->obj_f)
        {
            delete this->obj_f;
        }
    }

    template<typename T>
    Variant_t Variant::Create(const int& nRows, const int& nCols)
    {
        throw std::invalid_argument("unknown type");
    }

    template<>
    Variant_t Variant::Create<double>(const int& nRows, const int& nCols)
    {
        auto v = new arma::Mat<double>(nRows, nCols, arma::fill::zeros);
        return new Variant(v);
    }

    template<>
    Variant_t Variant::Create<int>(const int& nRows, const int& nCols)
    {
        auto v = new arma::Mat<int>(nRows, nCols, arma::fill::zeros);
        return new Variant(v);
    }

    template<typename T>
    arma::Mat<T>* Variant::Get()
    {
        throw std::invalid_argument("unknown type");
    }

    template<>
    arma::Mat<double>* Variant::Get()
    {
        if (this->obj_f == nullptr)
        {
            throw std::invalid_argument("wrong data type");
        }
        return this->obj_f;
    }

    template<>
    arma::Mat<int>* Variant::Get()
    {
        if (this->obj_i == nullptr)
        {
            throw std::invalid_argument("wrong data type");
        }
        return this->obj_i;
    }
}
