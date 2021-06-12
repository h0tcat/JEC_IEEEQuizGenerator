#pragma once

#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace nori{
    class Fraction{
        private:
            boost::multiprecision::cpp_dec_float_50 denominatorRaw=1,numeratorRaw=1;
            //分数に直した結果はintの方に値を入れる
            int denominator,numerator;

            
            int euclidean(int m, int n);
        public:

            Fraction();
            Fraction(
                    boost::multiprecision::cpp_dec_float_50 numerator,
                    boost::multiprecision::cpp_dec_float_50 denominator);

            void reduce();


            int getDenominator();
            int getNumerator();

            void setDenominator(boost::multiprecision::cpp_dec_float_50 denominator);
            void setNumerator(boost::multiprecision::cpp_dec_float_50 );
    };
};
