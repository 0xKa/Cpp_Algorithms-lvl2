//Fill array with random number from 1 to 100

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

int GenerateRandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
}

void PrintArrayWithRandomNumbers(int ArrayLength, int arr[100])
{
	cout << "Array Elementsn: ";

	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = GenerateRandomNumber(1, 100);
	
		cout << arr[i] << " ";

	}
}

int CheckForRepetedNumbersInArray(int ArrayLength, int arr[100], int NumberToCheck)
{
	int counter = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (NumberToCheck == arr[i])
			counter++;
	}

	return counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");

	PrintArrayWithRandomNumbers(ArrayLength, arr);

	int NumberToCheck = ReadPositiveNumber("\n\nEnter Number To Check For Repetition:");
	cout << "\nThe Number " << NumberToCheck << " is Repeted " << CheckForRepetedNumbersInArray(ArrayLength,arr,NumberToCheck) << " Time(s)";

	cout << endl << endl;
	return 0;
}
