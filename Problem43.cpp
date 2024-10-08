// Count Even Numbers in Array
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

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	arrLength = ReadPositiveNumber("Enter Positive Number:");

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void AddArrayElement(int num, int arr[100], int& ArrayLength)
{
	arr[ArrayLength] = num;
	ArrayLength++;

}

int CountEvenNumbersInArray(int arr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 == 0)
			counter++;
	}
	return counter;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;
	int arr2[100], arr2Length = 0;

	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "Array 1 Elements: ";
	PrintArray(arr, arrLength);

	cout << "Count of Even Numbers: " << CountEvenNumbersInArray(arr, arrLength) << endl;

	return 0;
}