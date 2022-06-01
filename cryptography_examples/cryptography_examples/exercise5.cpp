#include <iostream>
#include <string>

int ExtendedEuclideanAlgorithm(int numberA0, int numberA1) {
	//A0 und A1 defined above
	int numberA2 = 100;

	int q;

	int x0 = 1;
	int x1 = 0;
	int x2;

	int y0 = 0;
	int y1 = 1;
	int y2;

	do {
		q = numberA0 / numberA1;
		numberA2 = numberA0 - q * numberA1;
		x2 = x0 - q * x1;
		y2 = y0 - q * y1;

		numberA0 = numberA1;
		numberA1 = numberA2;
		x0 = x1;
		x1 = x2;
		y0 = y1;
		y1 = y2;

	} while (numberA1 != 0);

	return x0;
}

int GreatestCommonDivisor(int numberA, int numberB) {

	int remainder;
	int solution = 0;
	int round = 0;

	do {
		remainder = numberA % numberB;
		if (round == 0 && remainder == 0) {
			solution = numberB;
		}
		round++;

		numberA = numberB;
		numberB = remainder;
		if (remainder != 0) {
			solution = remainder;
		}

	} while (remainder != 0);

	return solution;
}

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
	// Umwandlung des Exponenten in Binärdarstellung
	std::string binaryNumber = convertDecimalToBinary(_exponents);

	// Beginne mit einer 1
	int result = 1;

	// Ersetzen jede 0 durch Q und jede 1 durch QM
	for (int i = 0; i < binaryNumber.size(); i++)
	{
		if (binaryNumber[i] == '1')
		{
			result = ((result * result) * _base) % _mod;
		}
		else
		{
			result = (result * result) % _mod;
		}
	}

	return result;
}

void exercise5() {
	int p,q,m,d,C;
	m = 212;

	std::cout << "Eingabe Primzahl p  ";
	std::cin >> p;
	std::cout << "Eingabe Primzahl q  ";
	std::cin >> q;

	int n = p * q;
	int phi = (p - 1) * (q - 1);
	int e = 3; //start mit 3

	std::cout << "\n";

	while (GreatestCommonDivisor(e, phi) != 1)
	{
		e = e + 2;
	}
	d = ExtendedEuclideanAlgorithm(e, phi);

	if (d < 0) {
		d += phi;
	}

	C = SquareAndMultiplyAlgorithmus(e, m, n);
	m = SquareAndMultiplyAlgorithmus(d, C, n);

	std::cout << "n = " << n << std::endl;
	std::cout << "phi = " << phi << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "public key P = " << e << "," << n << std::endl;
	std::cout << "public key S = " << d << "," << n << std::endl;

	std::cout << "C = " << C << std::endl;
}

