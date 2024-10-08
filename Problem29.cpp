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
	cout << "\n\nArray Elements: \n";

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

bool IsPrime(int num)
{
	int M = round(num / 2);
	for (int i = 2; i <= M; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void CopyOnlyPrimeNumbersToArray(int ArrayLength, int &Array2Length, int arrSource[100], int arrDestination[100])
{
	int counter = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (IsPrime(arrSource[i])) {
			arrDestination[counter] = arrSource[i];
			counter++;
		}
	}
	Array2Length = counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");

	FillArrayWithRandomNumbers(ArrayLength, arr);
	PrintArray(ArrayLength, arr);

	int arr2[100], Array2Length = 0;

	CopyOnlyPrimeNumbersToArray(ArrayLength, Array2Length, arr, arr2);
	PrintArray(Array2Length, arr2);

	

	cout << endl << endl;
	return 0;
}
