#include "RationalNumber.h"

using namespace std;

RationalNumber::RationalNumber() {
    numerator = Integer();
    denominator = NaturalNumber();

    //denominator.ADD_1N_N();
}



std::istream& operator>> (std::istream& str, RationalNumber& ratNum) {
    //  Кулебякин Илья 4308
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


RationalNumber RationalNumber::DIV_QQ_Q(RationalNumber n) {
	// this function devides one rational number by another
	RationalNumber nt;
	nt.numerator = this->numerator.MUL_ZZ_Z(Integer(n.denominator, true));
	nt.denominator = n.numerator.MUL_ZZ_Z(Integer(this->denominator, true)), true;	
	return nt;
}

RationalNumber RationalNumber::MUL_QQ_Q(RationalNumber multiplier) {
    if (!this->denominator.NZER_N_B() || !multiplier.denominator.NZER_N_B()){
        cerr << "Invalid fraction.\n";
        return
    }
    RationalNumber result;
    result.numerator = this->numerator.MUL_ZZ_Z(multiplier.numerator);
    result.denominator = this->denominator.MUL_NN_N(multiplier.denominator);
    result.RED_Q_Q();
    return result;
}

std::ostream& operator<< (std::ostream& str, const RationalNumber& ratNum) {
    // Кулебякин Илья 4308
    str << ratNum.numerator << '/' << ratNum.denominator;
    return str;
}
