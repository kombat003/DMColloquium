//
//  RationalNumber.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "RationalNumber.h"
using namespace std;

RationalNumber::RationalNumber() {
    numerator = Integer();
    denominator = NaturalNumber();
    //denominator.ADD_1N_N();
}

std::istream& operator>> (std::istream& str, RationalNumber& ratNum) {
    // Кулебякин Илья 4308
    string numStr;
    getline(str, numStr);
    auto endPos = remove(numStr.begin(), numStr.end(), ' ');
    numStr.erase(endPos, numStr.end());
    auto div = numStr.find('/');
    if (div == string::npos) {
        vector<unsigned int> vec(1);
        vec[0] = 1;
        ratNum.denominator = NaturalNumber(vec);
    } else {
        istringstream denominatorStream(numStr.substr(div+1));
        denominatorStream >> ratNum.denominator;
    }
    istringstream numeratorStream(numStr.substr(0, div));
    numeratorStream >> ratNum.numerator;
    
    return str;
    
}

std::ostream& operator<< (std::ostream& str, const RationalNumber& ratNum) {
    // Кулебякин Илья 4308
    str << ratNum.numerator << '/' << ratNum.denominator;
    return str;
}

Integer RationalNumber::TRAN_Q_Z(RationalNumber n) {
    return n.numerator;
}
