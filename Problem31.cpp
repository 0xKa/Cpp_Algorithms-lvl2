//Shuffle numbers in array


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

void Swap(int& X, int& Y)
{
	int Temp = Y;
	Y = X;
	X = Temp;

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

void FillArrayWithNumbersFrom1ToN(int ArrayLength, int arr[100])
{
	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = i + 1;
	}
}

void ShuffleArray(int ArrayLength, int arr[100])
{
	for (int i = 0; i < ArrayLength * 2; i++)
	{
		Swap(arr[GenerateRandomNumber(1, ArrayLength) - 1], arr[GenerateRandomNumber(1, ArrayLength) - 1]);
	}

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = ReadPositiveNumber("Enter Array Length:");


	FillArrayWithNumbersFrom1ToN(ArrayLength, arr);
	
	cout << "\nArray Elements Before Shuffle:\n";
	PrintArray(ArrayLength, arr);


	ShuffleArray(ArrayLength, arr);

	cout << "\nArray Elements Arter Shuffle:\n";
	PrintArray(ArrayLength, arr);


	cout << endl << endl;
	return 0;
}
