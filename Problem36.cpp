// check number in array


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

void AddUserNumberToTheArray(int num, int arr[100], int &ArrayLength)
{
		arr[ArrayLength] = num;
		ArrayLength++;

}

void FillUserNumberInArray(int arr[100], int &ArrayLength)
{
	bool AddMore = true;

	do
	{
		AddUserNumberToTheArray(ReadPositiveNumber("Enter Positive Number: "), arr, ArrayLength);

		cout << "Do You Want More Numbers In Array ? [0]No [1]Yes\n";
		cin >> AddMore;

	} while (AddMore);
}

void PrintArray(int arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << arr[i] << " ";
	}

}

int main()
{
	srand((unsigned)time(NULL));

	int ArrayLength = 0;
	int arr[100];

	FillUserNumberInArray(arr, ArrayLength);

	cout << "Array Elements:\n";
	PrintArray(arr, ArrayLength);


	cout << endl << endl;
	return 0;
}
