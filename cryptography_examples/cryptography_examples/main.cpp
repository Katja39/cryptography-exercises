#include "exercise1.h"
#include "exercise2.h"
#include <iostream>

int main()
{
	int input;
	int exit = false;

	while (exit == false) {
		std::cout << "\n----------------------------\n";
		std::cout << "Select exercise\n" <<
			"1: GCD and Extended Euclidean algorithm\n"
			"2: Vigenere Code, Frequency analysis of letters with Index of coincidence"
			"7: Exit\n";
		std::cout << "\n----------------------------\n";

		std::cin >> input;

		switch (input)
		{
		case 1:
			exercise();
			break;
		case 2:
			exercise2();
		case 7:
			exit = true;
			break;
		}
	}

	return 0;
}