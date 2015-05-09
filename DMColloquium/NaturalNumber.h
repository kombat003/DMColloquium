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



class NaturalNumber {
protected:
    // you must only use first 9 digits of each int.
    // So, if a number is: 12345678901234 than
    // digitBlocks[1] = 12345
    // digitBlocks[0] = 678901234
    std::vector<unsigned int> digitBlocks;
public:
    NaturalNumber();
    NaturalNumber(std::vector<unsigned int> digits):digitBlocks{digits}{};
    NaturalNumber ADD_1N_N();
    
    // put declarations-ONLY for each method below
};

#endif /* defined(__DMColloquium__NaturalNumber__) */