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

void NaturalNumber::setDigitsFromString(std::string numStr) {
    // Кулебякин Илья 4308
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
    // Кулебякин Илья 4308
    string numStr;
    getline(str, numStr);
    number.setDigitsFromString(numStr);
    return str;
}

void NaturalNumber::writeDigitsToStream(std::ostream& str) const {
    // Кулебякин Илья 4308
    str << digitBlocks[digitBlocks.size() -1];
    for (long long i = digitBlocks.size() - 2; i >= 0 ; --i) {
        unsigned int zeroMark = 100000000;
        while (digitBlocks[i] < zeroMark && zeroMark > 0) {
            str << '0';
            zeroMark /= 10;
        }
        str << digitBlocks[i];
    }
}

ostream& operator<< (ostream& str, const NaturalNumber& number) {
    // Кулебякин Илья 4308
    number.writeDigitsToStream(str);
    return str;
}

