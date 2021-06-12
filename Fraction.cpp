#include "Fraction.h"
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <cmath>


nori::Fraction::Fraction(){
    Fraction(1,1);
}
nori::Fraction::Fraction(
        boost::multiprecision::cpp_dec_float_50 numerator,
        boost::multiprecision::cpp_dec_float_50 denominator)
{
    this->numeratorRaw = numerator;
    this->denominatorRaw = denominator;
    
    numerator = 1;
    denominator = 1;
}



//ユークリッドの互除法
int nori::Fraction::euclidean(
        int m,
        int n)
{
    if(n==0){
        return m;
    }else{
        return euclidean(n, m % n);
    }
}
//約分関数
void nori::Fraction::reduce(){
    int eucResult=euclidean(numerator, denominator);

    setNumerator(numerator / eucResult);
    setDenominator(denominator / eucResult);
}

// ----

int nori::Fraction::getDenominator(){
    return nori::Fraction::denominator;
}
int nori::Fraction::getNumerator(){
    return nori::Fraction::numerator;
}

void nori::Fraction::setDenominator(boost::multiprecision::cpp_dec_float_50 denominatorRaw){
    this->denominatorRaw =  denominatorRaw;
    this->denominator = (int) this->denominatorRaw;
}
void nori::Fraction::setNumerator(boost::multiprecision::cpp_dec_float_50 numeratorRaw){
    this->numeratorRaw = numeratorRaw;
    this->numerator = (int) this->numeratorRaw;
}
