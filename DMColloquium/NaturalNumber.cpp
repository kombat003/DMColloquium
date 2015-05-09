//
//  NaturalNumber.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "NaturalNumber.h"
using namespace std;

// put definitions for all methods over here.

NaturalNumber::NaturalNumber() {
    digitBlocks = std::vector<unsigned int>(1);
    digitBlocks[0] = 0;
}

