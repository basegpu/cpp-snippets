#pragma once

#include <armadillo>

namespace container
{
    class Variant;
    typedef Variant* Variant_t;

    class Variant
    {
    public:
        template<typename T>
        static Variant_t Create(const int& nRows, const int& nCols);

        ~Variant();

        template<typename T>
        arma::Mat<T>* Get();

    private:
        enum class Type : char
        {
            Float,
            Integer
        };

        Variant(const Type& type, const int& nRows, const int& nCols);

        Type t;
        arma::Mat<int>* obj_i;
        arma::Mat<double>* obj_f;
    };
}
