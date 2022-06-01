#include <iostream>
#include <string>

void str_output(std::string input)
{
	int counter = 0;
	std::cout << input.length() << ": ";
	for (int i = 0; i < input.length(); i++)
	{
		if (counter < 7)
		{
			std::cout << input[i];
		}
		else
		{
			std::cout << input[i] << " ";
			counter = -1;
		}


		counter++;
	}
	std::cout << std::endl;
}

std::string shiftLeftOnce(std::string keyTmp)
{
	std::string shifted = "";
	for (int i = 1; i < 28; i++)
	{
		shifted += keyTmp[i];
	}
	shifted += keyTmp[0];
	return shifted;
}

std::string shiftLeftTwice(std::string keyTmp)
{
	std::string shifted = "";
	for (int i = 2; i < 28; i++)
	{
		shifted += keyTmp[i];
	}
	shifted += keyTmp[0];
	shifted += keyTmp[1];
	return shifted;
}

std::string getKey(std::string keyPerm56, int round)
{

	std::string x28 = keyPerm56.substr(0, 28);
	std::string y28 = keyPerm56.substr(28, 28);

	if (round == 1 || round == 2 || round == 9 || round == 16)
	{
		x28 = shiftLeftOnce(x28);
		y28 = shiftLeftOnce(y28);
	}
	else
	{
		x28 = shiftLeftTwice(x28);
		y28 = shiftLeftTwice(y28);
	}


	std::string keyCombined56 = x28 + y28;

	return keyCombined56;
}

std::string Xor(std::string a, std::string b)
{
	std::string result;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}

int binToDec(std::string num)
{
	int number = 0;
	int n = num.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if (num[i] == '1')
		{
			number += pow(2, n - i - 1);
		}
	}

	return number;
}

std::string binToDec(int number)
{
	std::string num = "0000";
	for (int i = 3; i >= 0; i--)
	{
		if (number % 2 == 1)
			num[i] = '1';
		number /= 2;
	}

	return num;
}

std::string sBoxSubstitution(std::string xored)
{
	int substitionBoxes[8][4][16] =
	{ {
		14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
		0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
		4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
		15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
	},
	{
		15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
	},
	{
		10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
	},
	{
		7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
	},
	{
		2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
	},
	{
		12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
	},
	{
		4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
	},
	{
		13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
	} };

	std::string sBoxed32 = "";
	std::string tmp = "";
	int counter = 0;
	int row = 0;
	int col = 0;
	std::string tmpRow = "";
	std::string tmpCol = "";
	for (int i = 0; i < 8; i++)
	{
		tmp = xored.substr(6 * i, 6);
		tmpRow = tmpRow + tmp[0] + tmp[5];
		tmpCol = tmpCol + tmp[1] + tmp[2] + tmp[3] + tmp[4];
		row = binToDec(tmpRow);
		col = binToDec(tmpCol);
		tmpRow.clear();
		tmpCol.clear();
		sBoxed32 += binToDec(substitionBoxes[i][row][col]);
	}
	return sBoxed32;
}

std::string desFunction(std::string right, std::string key48, int round)
{
	std::string expanded48 = "";
	std::string expXorKey48 = "";

	std::string sBoxed32 = "";
	std::string pPermuted32 = "";

	//Expansion
	int expansionMatrix[48] = {
	31,0,1,2,3,4,
	3,4,5,6,7,8,
	7,8,9,10,11,12,
	11,12,13,14,15,16,
	15,16,17,18,19,20,
	19,20,21,22,23,24,
	23,24,25,26,27,28,
	27,28,29,30,31,0
	};

	int pBoxPermutation[32] = {
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25
	};

	//Expansion Permuation
	for (int i = 0; i < 48; i++)
	{
		expanded48 += right[expansionMatrix[i]];
	}

	std::cout << "expansion:   "; str_output(expanded48);


	// key XOR expanded
	expXorKey48 = Xor(key48, expanded48);
	std::cout << "exp xor key: "; str_output(expXorKey48);


	//sBox - Substitution
	sBoxed32 = sBoxSubstitution(expXorKey48);
	std::cout << "sBox:        "; str_output(sBoxed32);


	//p-Box-Permutation
	for (int i = 0; i < 32; i++)
	{
		pPermuted32 += sBoxed32[pBoxPermutation[i] - 1];
	}

	std::cout << "pBox:        "; str_output(pPermuted32);

	return pPermuted32;
}

void exercise4()
{
	std::string input64 = "0000000100100011010001010110011110001001101010111100110111101111";
	std::string key64 = "0001001100110100010101110111100110011011101111001101111111110001";
	std::string keyPerm56 = "";
	std::string inputIp64 = "";
	std::string keyCompressed48 = "";
	std::string keyCombined56 = "";
	std::string pPermuted32 = "";
	std::string left32 = "";	//= inputIp64.substr(0, 32);
	std::string right32 = "";	//= inputIp64.substr(32, 32);
	std::string leftTmp32 = ""; //= inputIp64.substr(0, 32);
	std::string finalRound = "";
	std::string output64 = "";


	int initialPermutation[64] = {
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7
	};
	int keyPermutation[56] = {
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
	};
	int keyCompression[48] = {
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
	};
	int finalPermutation[64] = {
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25
	};

	std::cout << "initial input: "; str_output(input64);
	std::cout << "initial key:   "; str_output(key64);
	std::cout << "\n";

	// Initial Key Permutation
	for (int i = 0; i < 56; i++)
	{
		keyPerm56 += key64[keyPermutation[i] - 1];
	}

	// Initial Permutation
	for (int i = 0; i < 64; i++)
	{
		inputIp64 += input64[initialPermutation[i] - 1];
	}

	// Decomposition of permuted input vecotr  into L and R

	left32 = inputIp64.substr(0, 32);
	right32 = inputIp64.substr(32, 32);

	std::cout << "initial input permuted: "; str_output(inputIp64);
	std::cout << "initial key permuted:   "; str_output(keyPerm56);

	//16 Rounds
	for (int i = 0; i < 16; i++)
	{
		std::cout << std::endl << "Round " << i + 1 << std::endl;

		//Create Round Key
		keyPerm56 = getKey(keyPerm56, i + 1);
		std::cout << "keyperm56:  "; str_output(keyPerm56);
		for (int i = 0; i < 48; i++)
		{
			keyCompressed48 += keyPerm56[keyCompression[i] - 1];
		}
		std::cout << "key:         "; str_output(keyCompressed48);


		//Call f-Function
		pPermuted32 = desFunction(right32, keyCompressed48, i);

		leftTmp32 = left32;
		left32 = right32;
		right32 = Xor(pPermuted32, leftTmp32);


		keyCompressed48.clear();
	}

	finalRound = finalRound + right32 + left32;

	for (int i = 0; i < 64; i++)
	{
		output64 += finalRound[finalPermutation[i] - 1];
	}

	std::cout << "\n";
	std::cout << "Solution: "; str_output(output64);
}

