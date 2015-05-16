
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

