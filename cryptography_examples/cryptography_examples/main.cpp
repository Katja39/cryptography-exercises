#include "exercise1.h"
#include "exercise2.h"
#include "exercise3.h"
#include "exercise4.h"
#include <iostream>

int main()
{
	int input;
	int exit = false;

	while (exit == false) {
		std::cout << "\n----------------------------\n";
		std::cout << "Select exercise\n" <<
			"1: GCD and Extended Euclidean algorithm\n"
			"2: Vigenere Code, Frequency analysis of letters with Index of coincidence\n"
			"3: Blum-Blum-Shub Generator\n"
			"4: DES algorithm\n"
			"7: Exit";
		std::cout << "\n----------------------------\n";

		std::cin >> input;

		switch (input)
		{
		case 1:
			exercise();
			break;
		case 2:
			exercise2();
			break;
		case 3:
			exercise3();
			break;
		case 4:
			exercise4();
			break;
		case 7:
			exit = true;
			break;
		}
	}

	return 0;
}