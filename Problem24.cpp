//higher number of random array

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
	cout << "Array Elements: ";

	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = GenerateRandomNumber(1, 100);

		cout << arr[i] << " ";

	}
}

int GetTheHigherNumber(int ArrayLength, int arr[100])
{
	int Max = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (arr[i] > Max)
			Max = arr[i];
	}

	return Max;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");

	PrintArrayWithRandomNumbers(ArrayLength, arr);

	cout << "\n\nThe Higher Number is : " << GetTheHigherNumber(ArrayLength, arr);

	cout << endl << endl;
	return 0;
}
