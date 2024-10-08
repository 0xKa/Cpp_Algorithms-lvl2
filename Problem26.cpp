//sum of numbers in random array


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

int SumOfNumbersInArray(int ArrayLength, int arr[100])
{
	int sum = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");

	PrintArrayWithRandomNumbers(ArrayLength, arr);

	cout << "\n\nThe Sum of Numbers in Array = " << SumOfNumbersInArray(ArrayLength,arr);

	cout << endl << endl;
	return 0;
}
