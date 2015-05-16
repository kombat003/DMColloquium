
#include "NaturalNumber.h"
using namespace std;

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

NaturalNumber NaturalNumber::ADD_NN_N(NaturalNumber nat_num_2)
{
	//
	//  ADD_NN_N
	//  DMColloquium
	//
	//  Created by Dmitry Konstantinov, Dmitry Azarov & Tuyaara Fedorova on 5/7/15.
	//
	unsigned int length, min, flag;
	switch (this->COM_NN_D(nat_num_2))
	{
	case 2:
		length = this->digitBlocks.size() + 1;
		min = nat_num_2.digitBlocks.size();
		flag = 2;
		break;
	case 1:
		length = nat_num_2.digitBlocks.size() + 1;
		min = this->digitBlocks.size();
		flag = 1;
		break;
	case 0:
		length = this->digitBlocks.size() + 1;
		min = this->digitBlocks.size();
		break;
	default:
		break;
	}
	NaturalNumber result_of_sum;
	result_of_sum.digitBlocks = std::vector<unsigned int>(length);
	for (int j = 0; j < min; j++) {
		result_of_sum.digitBlocks[j] += (nat_num_2.digitBlocks[j] + this->digitBlocks[j]); // суммируем последние разряды чисел
		result_of_sum.digitBlocks[j + 1] += result_of_sum.digitBlocks[j] / 1000000000; 
		result_of_sum.digitBlocks[j] = result_of_sum.digitBlocks[j] % 1000000000;
	}
	switch (flag)
	{
	case 2:
		for (int i = nat_num_2.digitBlocks.size(); i < length - 1; i++) {
			result_of_sum.digitBlocks[i] += this->digitBlocks[i];
			result_of_sum.digitBlocks[i + 1] += result_of_sum.digitBlocks[i] / 1000000000; // если есть разряд для переноса, переносим его в следующий разряд
			result_of_sum.digitBlocks[i] = result_of_sum.digitBlocks[i] % 1000000000; // если есть разряд для переноса он отсекается
		}
		break;
	case 1:
		for (int i = this->digitBlocks.size(); i < length - 1; i++) {
			result_of_sum.digitBlocks[i] += nat_num_2.digitBlocks[i];
			result_of_sum.digitBlocks[i + 1] += (result_of_sum.digitBlocks[i] / 1000000000); // если есть разряд для переноса, переносим его в следующий разряд
			result_of_sum.digitBlocks[i] = result_of_sum.digitBlocks[i] % 1000000000; // если есть разряд для переноса он отсекается
		}
		break;
	default:
		break;
	}
	if (result_of_sum.digitBlocks[length - 1] == 0) {
		length--;
	}
	return result_of_sum;
}



int NaturalNumber::COM_NN_D(NaturalNumber n) {
    // this function compares two natural numbers:
    // if n1 = n2, function returns 0;
    // if n1 > n2, function returns 2;
    // else function returns 1
    if (this->digitBlocks == n.digitBlocks) return 0;
    if (this->digitBlocks.size() > n.digitBlocks.size()) return 2;
    if (this->digitBlocks.size() == n.digitBlocks.size()) {
        int i = this->digitBlocks.size() - 1;
        for (int j = i; j > -1; --j) {
           if (this->digitBlocks[j] > n.digitBlocks[j])
                return 2;
            else if (this->digitBlocks[j] < n.digitBlocks[j])
                return 1;
            }
        }
    return 1;
}

// Задача N-3, группа: Кожевников Никита, Ташланов Андрей
NaturalNumber NaturalNumber::ADD_1N_N(){
	NaturalNumber result = *this;

	for (unsigned int i = 0; i < result.digitBlocks.size(); i++)
	{
		if (result.digitBlocks[i] != 999999999)
		{
			result.digitBlocks[i] += 1;
			break;
		}
		else
			result.digitBlocks[i] = 0;
	
		if ((i+1) == result.digitBlocks.size())
		{
			result.digitBlocks.push_back(1);
			break;
		}
	}

    return result;
}
