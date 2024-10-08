// Copy Array In Reverse Order

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

void PrintArray(int ArrayLength, int arr[100])
{

	for (int i = 0; i < ArrayLength; i++)
	{

		cout << arr[i] << " ";

	}
}

void FillArrayWithRandomNumbers(int ArrayLength, int arr[100])
{
	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = GenerateRandomNumber(1,100);
	}
}

void CopyArrayInReverseOrder(int ArrayLegnth, int arrSource[100], int arrDestination[100])
{
	//int j = ArrayLegnth - 1;
	for (int i = 0; i < ArrayLegnth; i++)
	{
		arrDestination[i] = arrSource[ArrayLegnth - i - 1];
		//j--;

	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");
	int arr2[100];


	FillArrayWithRandomNumbers(ArrayLength, arr);
	cout << "\nArray Elements:\n";
	PrintArray(ArrayLength, arr);

	
	CopyArrayInReverseOrder(ArrayLength, arr, arr2);
	cout << "\n\nArray Elements After Copy:\n";
	PrintArray(ArrayLength, arr2);



	cout << endl << endl;
	return 0;
}
