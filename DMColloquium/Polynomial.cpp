//
//  Polynomial.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "Polynomial.h"
using namespace std;
Polynomial::Polynomial() {
    coefficients = vector<RationalNumber>(1);
    
}

std::istream& operator>> (std::istream& str, Polynomial& polinom) {
    // Кулебякин Илья 4308
    string strNum;
    getline(str, strNum);
    vector<size_t> occurances;
    size_t pos = strNum.find(',', 0);
    polinom.coefficients = vector<RationalNumber>(0);
    
    while (pos != string::npos) {
        occurances.push_back(pos);
        pos = strNum.find(',', pos+1);
    }
    
    for (long long i = occurances.size(); i >= 0; --i) {
        size_t start = (i==0 ? 0 : occurances[i-1]+1);
        size_t len = (i == occurances.size() ? strNum.size() : occurances[i]) - start;
        istringstream coeffStream(strNum.substr( start , len));
        RationalNumber ratNum;
        coeffStream >> ratNum;
        polinom.coefficients.push_back(ratNum);
    }
    
    return str;
}

std::ostream& operator<< (std::ostream& str, const Polynomial& polinom) {
    // Кулебякин Илья 4308
    for (long long i  = polinom.coefficients.size() - 1 ; i >= 0; --i) {
        str << '(' << polinom.coefficients[i];
        if (i != 0) {
            str << ")x^" << i << " + ";
        } else {
            str << ')';
        }
    }
    
    
    return str;
}