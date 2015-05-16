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
    string numStr;
    getline(str, numStr);
    auto endPos = remove(numStr.begin(), numStr.end(), ' ');
    numStr.erase(endPos, numStr.end());
    auto div = numStr.find('/');
    if (div == string::npos) {
        ratNum.denominator = NaturalNumber();
    } else {
        istringstream denominatorStream(numStr.substr(div+1));
        denominatorStream >> ratNum.denominator;
    }
    istringstream numeratorStream(numStr.substr(0, div));
    numeratorStream >> ratNum.numerator;
    
    return str;
    
}

RationalNumber RationalNumber::SUB_QQ_Q(RationalNumber rat_num_2)
{
	//
	//  SUB_QQ_Q
	//  DMColloquium
	//
	//  Created by Dmitry Konstantinov, Dmitry Azarov & Tuyaara Fedorova on 8/7/15.
	//
	RationalNumber result;
	if (!this->denominator.NZER_N_B() || !rat_num_2.denominator.NZER_N_B())
	{
		result.denominator = denominator.LCM_NN_N(rat_num_2.denominator);
		this->numerator = this->numerator.MUL_ZZ_Z(this->numerator.TRANS_N_Z(result.denominator.DIV_NN_N(this->denominator)));
		rat_num_2.numerator = rat_num_2.numerator.MUL_ZZ_Z(rat_num_2.numerator.TRANS_N_Z(result.denominator.DIV_NN_N(rat_num_2.denominator)));
		result.numerator = this->numerator.SUB_ZZ_Z(rat_num_2.numerator);
	}
	else
	{
		//ERR: denominator = 0
	}
	return result;
}