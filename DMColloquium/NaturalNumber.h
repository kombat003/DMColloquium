//
//  NaturalNumber.h
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#ifndef __DMColloquium__NaturalNumber__
#define __DMColloquium__NaturalNumber__

#include <vector>

#endif /* defined(__DMColloquium__NaturalNumber__) */

class NaturalNumber {
protected:
    std::vector<unsigned int> digitBlocks;
public:
    NaturalNumber greatestCommonFactor(NaturalNumber secondNumber);
    // put declarations-ONLY for each method below
};