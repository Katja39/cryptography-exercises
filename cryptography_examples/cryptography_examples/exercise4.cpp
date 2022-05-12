#include <iostream>

using namespace std;

string input64 = "0000000100100011010001010110011110001001101010111100110111101111";//65
string initialKey = "0001001100110100010101110111100110011011101111001101111111110001";

void initialPermutation(string inputPermuted[65], string keyPermuted[57]) {
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

	//Input
	cout << "Input Permuted:"<<endl;
	for (int i = 0; i < 64; i++)
	{
		inputPermuted[i] = input64[initialPermutation[i]-1];
	}
	for (int i = 0; i < 64; i++)
	{
		cout << inputPermuted[i];
	}
	cout << endl;

	//Key
	cout << "Key Permuted:"<<endl;
	for (int i = 0; i < 56; i++)
	{
		keyPermuted[i] = initialKey[keyPermutation[i] - 1];
	}
	for (int i = 0; i < 56; i++)
	{
		cout << keyPermuted[i];
	}
	cout << endl;
}
string * finalPermutation(string inputPermuted[65]) {
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
	string* y=new string[65];

	//Input
	for (int i = 0; i < 64; i++)
	{
		y[i] = inputPermuted[finalPermutation[i] - 1];
	}

	return y;
}

void expansionspermutation(string right[32]) {//TODO
	

}

void exercise4() {
	string inputPermuted[65];
	string keyPermuted[57];

	initialPermutation(inputPermuted,keyPermuted);

	string left[32];
	string right[32];

	for (int i = 0; i < 32; i++)
	{
		left[i] = inputPermuted[i];
	}
	for (int i = 0; i < 32; i++)
	{
		right[i] = inputPermuted[i + 32];
	}
	expansionspermutation(right);


	string *p = finalPermutation(inputPermuted);

	cout << endl;
	cout << "After final permutation"<<endl;
	for (int i = 0; i < 64; i++) {
		cout << *(p + i);
	}
}

