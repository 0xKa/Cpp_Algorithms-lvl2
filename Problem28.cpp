//average of numbers in random array


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

void FillArrayWithRandomNumbers(int ArrayLength, int arr[100])
{

	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = GenerateRandomNumber(1, 100);


	}
}

void PrintArray(int ArrayLength, int arr[100])
{
	cout << "\n\nArray Elements: ";

	for (int i = 0; i < ArrayLength; i++)
	{

		cout << arr[i] << " ";

	}
}

void CopyArray(int ArrayLength, int arrSource[100], int arrDestination[100])
{
	for (int i = 0; i < ArrayLength; i++)
		arrDestination[i] = arrSource[i];
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");

	FillArrayWithRandomNumbers(ArrayLength, arr);
	PrintArray(ArrayLength, arr);

	int arr2[100];

	CopyArray(ArrayLength, arr, arr2);
	PrintArray(ArrayLength, arr2);

	cout << endl << endl;
	return 0;
}
