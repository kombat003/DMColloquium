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

// Задача P-2, группа: Кожевников Никита, Ташланов Андрей
Polynomial Polynomial::SUB_PP_P(Polynomial SecondPoly)
{
	Polynomial result = *this;
	unsigned int i;

	if (result.coefficients.size() >= SecondPoly.coefficients.size()) // Если первый многочлен больше второго или равен ему
	{
		for (i = 0; i < SecondPoly.coefficients.size(); i++)
			result.coefficients[i] = result.coefficients[i].SUB_QQ_Q(SecondPoly.coefficients[i]);
	}
	else
	{
		for (i = 0; i < result.coefficients.size(); i++)
			result.coefficients[i] = result.coefficients[i].SUB_QQ_Q(SecondPoly.coefficients[i]);
		for (RationalNumber null; i < SecondPoly.coefficients.size(); i++) // Создаётся объект null рационального типа (дробь 0/1). Из него вычитаются коэффициенты второго многочлена в том случае, если первый многочлен оказался меньше и его дальнейшие коэффициенты, из которых нужно вычитать, отсутствуют.
			result.coefficients[i] = null.SUB_QQ_Q(SecondPoly.coefficients[i]);
	}

	return result;
}
}