// copy Distinct numbers from array 
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
	arrlength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] == Number)
			return i;//return the index   
	} //if you reached here, this means the number is not found
	return -1;
} 

bool IsNumberInArray(int Number, int arr[100], int arrLength) 
{ 
	return FindNumberPositionInArray(Number, arr, arrLength) != -1;
} 

void AddArrayElement(int num, int arr[100], int& ArrayLength)
{
	arr[ArrayLength] = num;
	ArrayLength++;

}

void CopyDistinctNumber(int arrSource[100], int arrDistination[100], int arrSourceLength, int& arrDistinationLength)
{
	for (int i = 0; i < arrSourceLength; i++)
	{
		if (IsNumberInArray(arrSource[i], arrDistination, arrDistinationLength) != true)
			AddArrayElement(arrSource[i], arrDistination, arrDistinationLength);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;
	int arr2[100], arr2Length = 0;

	FillArray(arr, arrLength);
	cout << "Array 1 Elements: ";
	PrintArray(arr, arrLength);

	CopyDistinctNumber(arr, arr2, arrLength, arr2Length);
	cout << "Array 2 Elements: ";
	PrintArray(arr2, arr2Length);



	return 0;
}