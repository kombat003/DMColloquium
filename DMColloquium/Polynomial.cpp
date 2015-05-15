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

RationalNumber Polynomial::LED_P_Z()
{
	if (!coefficients.empty())
		return coefficients.back(); // do something about it
	else
	{
		RationalNumber X;
		return X;
	}
    
}

std::istream& operator>> (std::istream& str, Polynomial& polinom) {
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