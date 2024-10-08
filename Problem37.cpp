// copy array using AddArrayElement function (old function was on Problem #28)
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
	cout << endl <<endl;
}

/*void CopyArray(int arrLength, int arrSource[100], int arrDestenation[100])
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestenation[i] = arrSource[i];
	}
}*/    //CopyArray() function from problem 28//

void AddArrayElement(int num, int arr[100], int& ArrayLength)
{
	arr[ArrayLength] = num;
	ArrayLength++;

}

void CopyArray(int arrSource[100], int arrDestination[100], int arrSourceLength, int& arrDestinationLength)//using AddArrayElement function
{
	for (int i = 0; i < arrSourceLength; i++)
	{
		AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;
	int arr2[100], arr2Length = 0;

	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "Array 1 Elements: ";
	PrintArray(arr, arrLength);
	


	CopyArray(arr,arr2,arrLength,arr2Length);
	cout << "Array 2 Elements: ";
	PrintArray(arr2, arr2Length);
	
	return 0;
}