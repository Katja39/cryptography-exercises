#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;
void exercise2() {
	//Task 1
	cout << "Task 1: Vigenere Code: "<<endl;
	
	string plainText = "SECRETTEXT";
	string cipherText = plainText;
	string key = "KEYKEYKEYK";

	cout << "The length of the Text is: " << plainText.length() << endl;

	for (int i = 0; i < plainText.length(); i++)
	{
		cipherText[i] = (((int)plainText[i] + (int)key[i % key.length()]) % 26) + 65;
		
	}

	cout << "ciphertext: " << cipherText << endl;

	//Task 2
	cout <<"\nTask 2: Frequency analysis of letters with Index of coincidence \n" << endl;

	const int numberOfLettersAlphabet = 26;

	int alphabet[numberOfLettersAlphabet] = { 0 };
	int offset = 65;

	std::ifstream text("exercise2_chiffre.txt");
	std::string chiffre((std::istreambuf_iterator<char>(text)),
		std::istreambuf_iterator<char>());

	for (int i = 0; i < chiffre.length(); i++)
	{
		if ((chiffre[i] - offset < 26) && (chiffre[i] - offset >= 0))
		{
			alphabet[chiffre[i] - offset] ++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << (char)(i + offset) << " = " << alphabet[i] << endl;
	}


	float indexOfCoincidence;
	int numberOfLetters = chiffre.length();

	float sumOfAllPairsOfEqualLetters = 0;
	float sumOfAllLetterPairs = 0;

	for (int i = 0; i < numberOfLettersAlphabet; i++)
	{
		sumOfAllPairsOfEqualLetters += alphabet[i] * (alphabet[i] - 1);
		sumOfAllLetterPairs += alphabet[i];
	}

	indexOfCoincidence = sumOfAllPairsOfEqualLetters / (sumOfAllLetterPairs * (sumOfAllLetterPairs - 1));

	cout <<"\nIndex of coincidence: " << indexOfCoincidence << endl;
}