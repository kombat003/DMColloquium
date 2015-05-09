//
//  Polynomial.h
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#ifndef __DMColloquium__Polynomial__
#define __DMColloquium__Polynomial__

#include "RationalNumber.h"



class Polynomial {
private:
    std::vector<RationalNumber> coefficients;
public:
    Polynomial();
    Polynomial(std::vector<RationalNumber> coeff):coefficients{coeff}{};
};

#endif /* defined(__DMColloquium__Polynomial__) */