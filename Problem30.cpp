//copy prime number array


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

void GetSumOf2Arrays(int ArrayLength, int arr[100], int arr2[100], int arrResult[100])
{
	for (int i = 0; i < ArrayLength; i++)
	{
		arrResult[i] = arr[i] + arr2[i];
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");
	int arr2[100];
	int arr3[100];

	FillArrayWithRandomNumbers(ArrayLength, arr);
	FillArrayWithRandomNumbers(ArrayLength, arr2);
	GetSumOf2Arrays(ArrayLength, arr, arr2, arr3);


	cout << "\n\nArray 1 Elements: \n";
	PrintArray(ArrayLength, arr);

	
	cout << "\n\nArray 2 Elements: \n";
	PrintArray(ArrayLength, arr2);

	
	cout << "\n\nArray 3 Elements: \n";
	PrintArray(ArrayLength, arr3);

	cout << endl << endl;
	return 0;
}
