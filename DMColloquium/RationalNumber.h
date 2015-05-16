//
//  RationalNumber.h
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#ifndef __DMColloquium__RationalNumber__
#define __DMColloquium__RationalNumber__

#include "Integer.h"
#include "NaturalNumber.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class RationalNumber {
private:
    Integer numerator;
    NaturalNumber denominator;
public:
    // Instanciates a rational number (0/1)
    RationalNumber();
    RationalNumber(Integer numerator, NaturalNumber denominator):numerator{numerator},denominator{denominator}{};
    
    // "numerator/denominator" ("-23541234123512351235/124612354123512351236")
    friend std::istream& operator>> (std::istream& str, RationalNumber& ratNum);
    friend std::ostream& operator<< (std::ostream& str, const RationalNumber& ratNum);
};

#endif