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

bool NaturalNumber::NZER_N_B()
{
    for (int i = 0; i < digitBlocks.size(); i++)
    {
        if (digitBlocks[i] != 0)
            return true;
    }
    return false;
}

void NaturalNumber::setDigitsFromString(std::string numStr) {
    auto endPos = remove(numStr.begin(), numStr.end(), ' ');
    numStr.erase(endPos, numStr.end());
    
    unsigned long numOfBlock = (numStr.length() - 1) / 9;
    long long numOfElement = (numStr.length() - 1) % 9;
    digitBlocks.resize(numOfBlock+1);
    for (long long i = 0; i < numStr.length(); ++i) {
        char c = numStr[i];
        digitBlocks[numOfBlock] += (c - '0') * pow(10, numOfElement--);
        if (numOfElement < 0) {
            --numOfBlock;
            numOfElement = 8;
        }
        
    }
}

istream& operator>> (istream& str, NaturalNumber& number)  {
    string numStr;
    getline(str, numStr);
    number.setDigitsFromString(numStr);
    return str;
}

