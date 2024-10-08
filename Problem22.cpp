// check for repeated number inarray

#include <iostream>
using namespace std;

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

void ReadArrayElements(int Element[100], int &ArrayLength)
{

	cout << "Enter Array Length: \n";
	cin >> ArrayLength;

	cout << "Enter Array Elements: \n";

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> Element[i];
	}
	cout << endl;
}

void PrintArrayElements(int Element[100], int ArrayLength)
{
	cout << "Array Elements : ";
	for (int i = 0; i  < ArrayLength; i++)
	{
		cout << Element[i] << " ";
	}
	cout << endl;
}

int CheckForRepetedNumberInArray(int Element[100], int ArrayLength, int NumberToCheck)
{
	int counter = 0;
	for (int i = 0; i <= ArrayLength; i++)
	{
		if (NumberToCheck == Element[i])
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	int Element[100], ArrayLength = 0;

	ReadArrayElements(Element, ArrayLength);
	PrintArrayElements(Element, ArrayLength);

	int NumberToCheck = ReadPositiveNumber("\nEnter The Number You Want To Check: ");

	cout << NumberToCheck << " Is Repeted " << CheckForRepetedNumberInArray(Element,ArrayLength,NumberToCheck) << " Time(s)";


	cout << endl << endl;
	return 0;
}
