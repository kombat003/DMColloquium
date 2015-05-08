//
//  NaturalNumber.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "NaturalNumber.h"

// put definitions for all methods over here.

/// This is just an example of how to get going. Doesn't make any sense
bool NaturalNumber::NZER_N_B()
{
	for (int i = 0; i < digitBlocks.size(); i++)
	{
		if (digitBlocks[i] != 0)
			return true;
	}
		return false;
}
NaturalNumber NaturalNumber::greatestCommonFactor(NaturalNumber secondNumber){
    return *this;
}
