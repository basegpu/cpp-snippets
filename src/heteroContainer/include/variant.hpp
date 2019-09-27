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

        Variant(arma::Mat<int>* const obj);
        Variant(arma::Mat<double>* const obj);

        arma::Mat<int>* const obj_i;
        arma::Mat<double>* const obj_f;
    };
}
