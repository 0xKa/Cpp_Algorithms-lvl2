// check number in array


#include <iostream>
using namespace std;


int RandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
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

void FillArrayWithRandomNumbers(int ArrayLength, int arr[100])
{
	for (int i = 0; i < ArrayLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int ArrayLength, int arr[100])
{

	for (int i = 0; i < ArrayLength; i++)
	{

		cout << arr[i] << " ";

	}

}

int FindNumberPositionInArray(int ArrayLength, int arr[100], int NumberToFind)
{
	for (int i = 0; i < ArrayLength; i++)
	{

		if (arr[i] == NumberToFind)
		{
			return i;
		}
	}

	return -1;
}

bool CheckNumberInArray(int ArrayLength, int arr[100],int NumberToFind)
{

	return (FindNumberPositionInArray(ArrayLength,arr,NumberToFind) != -1);
}

int main()
{
	srand((unsigned)time(NULL));

	int ArrayLength = ReadPositiveNumber("Enter Array Length:");
	int arr[100];

	FillArrayWithRandomNumbers(ArrayLength, arr);
	cout << "Array Elements:\n";
	PrintArray(ArrayLength, arr);

	int NumberToFind = ReadPositiveNumber("\nEnter Number To Search For:");
	cout << "\nThe Number You Are Looking For = " << NumberToFind << endl;


	if (CheckNumberInArray(ArrayLength, arr, NumberToFind))
		cout << "Yes The Number Is Found :)";
	else
		cout << "No The Number Is Not Found :(";
	

	cout << endl << endl;
	return 0;
}
