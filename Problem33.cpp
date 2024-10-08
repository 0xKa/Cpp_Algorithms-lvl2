// Generate keys in array

#include <iostream>
using namespace std;

enum enumCharType { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4 };

int RandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
}

char GetRandomCharType(enumCharType chartype)
{
	// not necessery to use char()
	switch (chartype) {
	case (SmallLetter):
		return char(RandomNumber(97, 122));
	case (CapitalLetter):
		return char(RandomNumber(65, 90));
	case (SpecialChar):
		return char(RandomNumber(33, 47));
	case (Digit):
		return char(RandomNumber(48, 57));

	}

}

string GenerateWord(enumCharType CharType, int WordLength)
{
	string word;
	for (int i = 1; i <= WordLength; i++)
	{
		word = word + GetRandomCharType(CharType);
	}
	return word;
}

string GenerateKey()
{

	int l = 5;

	string Key = GenerateWord(CapitalLetter, l) + "-";
	Key = Key + GenerateWord(CapitalLetter, l) + "-";
	Key = Key + GenerateWord(CapitalLetter, l) + "-";
	Key = Key + GenerateWord(CapitalLetter, l);


	return Key;
}

int ReadPositiveNumber(string massage)
{
	int num;
	do
	{
		cout << massage << endl;
		cin >> num;

	} while (num < 0);
	return num;
}

void PrintStringArray(int ArrayLength, string arr[100])
{

	for (int i = 0; i < ArrayLength; i++)
	{

		cout << "Array[" << i << "] : " << arr[i] << endl;

	}
}

void FillArrayWithKeys(int ArrayLegnth, string arr[100])
{
	for (int i = 0; i < ArrayLegnth; i++)
	{
		arr[i] = GenerateKey();
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int ArrayLength = ReadPositiveNumber("Enter Array Length:");
	string arr[100];

	FillArrayWithKeys(ArrayLength, arr);

	PrintStringArray(ArrayLength, arr);



	cout << endl << endl;
	return 0;
}
