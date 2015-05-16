#ifndef __DMColloquium__RationalNumber__
#define __DMColloquium__RationalNumber__

#include "Integer.h"
#include "NaturalNumber.h"
#include <iostream>
#include <string>
#include <sstream>



class RationalNumber {
private:
    Integer numerator;
    NaturalNumber denominator;
public:
    RationalNumber();
    RationalNumber(Integer numerator, NaturalNumber denominator):numerator{numerator},denominator{denominator}{};

    
    // "numerator/denominator" ("-23541234123512351235/124612354123512351236")
    friend std::istream& operator>> (std::istream& str, RationalNumber& ratNum);
    RationalNumber SUB_QQ_Q(RationalNumber rat_num_2);

    RationalNumber DIV_QQ_Q(RationalNumber);
};

#endif /*defined(__DMColloquium__RationalNumber__)*/
