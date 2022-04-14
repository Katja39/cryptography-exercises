
#include <iostream>
void exercise() {
	//test: http://public.hochschule-trier.de/~knorr/exeuclid.php?a=93&b=42&submit=Berechnen

	std::cout << "\nTask 1: Greatest common divisor\n";

	int numberA;
	int numberB;

	std::cout << "Input A\n";
	std::cin >> numberA;
	std::cout << "Input B\n";
	std::cin >> numberB;

	int remainder;
	int solution=0;
	int round = 0;

	int numberA0 = numberA; //Numbers for Euclid
	int numberA1 = numberB; //Numbers for Euclid

	do {
		remainder=numberA% numberB;
		if (round == 0 && remainder == 0) {
			solution = numberB;
		}
		round++;

		numberA = numberB;
		numberB=remainder;
		if (remainder != 0) {
			solution = remainder;
		}
		std::cout << remainder<<std::endl;

	} while (remainder != 0);

	std::cout << "\nSolution GCD: " << solution<<"\n\n";

	std::cout << "Task 2: Extended Euclidean algorithm" << std::endl;

	//A0 und A1 defined above
	int numberA2 = 100;

	int q;

	int x0=1;
	int x1=0;
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

		if (numberA1 != 0) {
			solution = numberA1;
		}

	} while (numberA1 != 0);

	std::cout <<"\nSolution of Extended Euclidean algorithm "<<"\n";

	std::cout << "x = " << x0 << std::endl;
	std::cout << "y = " << y0 << std::endl;
}