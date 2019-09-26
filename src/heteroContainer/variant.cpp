#include <armadillo>
#include <exception>
#include "variant.hpp"

namespace container
{
    Variant::Variant(const Type& type, const int& nRows, const int& nCols) :
        t(type),
        obj_i(nullptr),
        obj_f(nullptr)
    {
        switch (this->t)
        {
            case Type::Float:
            {
                this->obj_f = new arma::Mat<double>(nRows, nCols, arma::fill::zeros);
                return;
            }
            case Type::Integer:
            {
                this->obj_i = new arma::Mat<int>(nRows, nCols, arma::fill::zeros);
                return;
            }
        }
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
        return new Variant(Variant::Type::Float, nRows, nCols);
    }

    template<>
    Variant_t Variant::Create<int>(const int& nRows, const int& nCols)
    {
        return new Variant(Variant::Type::Integer, nRows, nCols);
    }

    template<typename T>
    arma::Mat<T>* Variant::Get()
    {
        throw std::invalid_argument("unknown type");
    }

    template<>
    arma::Mat<double>* Variant::Get()
    {
        return this->obj_f;
    }

    template<>
    arma::Mat<int>* Variant::Get()
    {
        return this->obj_i;
    }
}
