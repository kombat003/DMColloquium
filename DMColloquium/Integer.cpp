//
//  Integer.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "Integer.h"
using namespace std;

Integer::Integer() {
    digitBlocks = vector<unsigned int>(1);
    digitBlocks[0] = 0;
    isPositive = true;
}

Integer::Integer(vector<unsigned int> digits, bool isPositive) {
    digitBlocks = digits;
    this->isPositive = isPositive;
}

std::istream& operator>> (std::istream& str, Integer& integer) {
    // Кулебякин Илья 4308
    string numString;
    getline(str, numString);
    
    if (!isdigit(numString[0])) {
        integer.isPositive = (numString[0] != '-');
        numString = numString.substr(1);
    } else {
        integer.isPositive = true;
    }
    
    integer.setDigitsFromString(numString);
    
    NaturalNumber natNum;
    
    return str;
}

ostream& operator<< (ostream& str, const Integer& number) {
    // Кулебякин Илья 4308
    if (!number.isPositive) {
        str << '-';
    }
    number.writeDigitsToStream(str);
    return str;
}