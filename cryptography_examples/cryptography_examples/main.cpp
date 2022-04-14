#include "exercise1.h"
#include <iostream>

int main()
{
	int input;
	int exit = false;

	while (exit == false) {
		std::cout << "\n----------------------------\n";
		std::cout << "Select exercise\n" <<
			"1: GCD and Extended Euclidean algorithm\n"
			"7: Exit\n";
		std::cout << "\n----------------------------\n";

		std::cin >> input;

		switch (input)
		{
		case 1:
			exercise();
			break;
		case 7:
			exit = true;
			break;
		}
	}

	return 0;
}