// Check if Array is palindrome array or not 
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

void FillArray(int arr[100], int& arrlength)
{
	// Hardcoded Elements
	arrlength = 5;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 20;
	arr[4] = 10;

}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

bool IsPalindromeArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] != arr[arrLength - i - 1])
			return false;
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;
	int arr2[100], arr2Length = 0;

	FillArray(arr, arrLength);
	cout << "Array 1 Elements: ";
	PrintArray(arr, arrLength);

	if (IsPalindromeArray(arr, arrLength))
		cout << "\nArray is Palindrome";
	else
		cout << "\nArray is NOT Palindrome";

	return 0;
}