#include <iostream>

std::string convertDecimalToBinary(int decimal)
{
	std::string binary;
	while (decimal != 0) {
		binary = (decimal % 2 == 0 ? "0" : "1") + binary;
		decimal = decimal / 2;
	}
	while (binary.length() < 4) {
		binary = "0" + binary;
	}
	return binary;
}

int SquareAndMultiplyAlgorithmus(int _exponents, int _base, int _mod)
{
	// Umwandlung des Exponenten in Binaer
	std::string binaryNumber = convertDecimalToBinary(_exponents);

	int result = 1;

	for (int i = 0; i < binaryNumber.size(); i++)
	{
		if (binaryNumber[i] == '1')
		{
			result = ((result * result) % _mod * _base) % _mod;
		}
		else
		{
			result = (result * result) % _mod;
		}
	}

	return result;
}

void exercise6() {
	int p = 12347;
	int alpha = 2;
	int beta = 8461;

	int x1[3] = { 5692,1220,212 };
	int x2[3] = { 144,54,4214 };

	int h;

	for (int i = 0; i < 3; i++)
	{
		h = SquareAndMultiplyAlgorithmus(x1[i], alpha, p);//exponent,base,mod
		h *= SquareAndMultiplyAlgorithmus(x2[i], beta, p);
		h = h % p;
		std::cout << "h" << i + 1 << ": " << h << std::endl;
	}
}