#include <iostream>

using namespace std;
void exercise3() {
	cout << "\np=7; q=19; s=2"<<endl;
	int p = 7;
	int q = 19;
	int s = 2;
	int n,x,b;
	
	n = p * q;
	x = s * s % n;

	for (int i = 0; i < 18; i++)
	{
		x = x * x % n;
		b = x % 2;

		cout << b;
	}

	cout << "\np=47; q=67; s=6" << endl;
	p = 47;
	q = 67;
	s = 6;

	n = p * q;
	x = s * s % n;

	for (int i = 0; i < 18; i++)
	{
		x = x * x % n;
		b = x % 2;

		cout << b;
	}
	cout << endl;
}