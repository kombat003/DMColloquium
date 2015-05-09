//
//  Integer.h
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#ifndef __DMColloquium__Integer__
#define __DMColloquium__Integer__

#include "NaturalNumber.h"
#include <vector>

class Integer : public NaturalNumber {
private:
    bool isPositive;
public:
    Integer();
    Integer(std::vector<unsigned int> digits, bool isPositive);
    Integer(NaturalNumber natural, bool isPositive):NaturalNumber{natural},isPositive{isPositive}{};
    
};


#endif /* defined(__DMColloquium__Integer__) */