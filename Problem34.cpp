// return number in index array


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
//////////////////////////////// (My Soluation)////////////
//void LocateNumberInArray(int ArrayLength, int arr[100], int NumberToFind)
//{
//	cout << "\n\nThe Number You Are Looking For Is: " << NumberToFind << endl;
//
//	for (int i = 0; i < ArrayLength; i++)
//	{
//
//		if (arr[i] == NumberToFind)
//		{
//			cout << "The Number Found at Position: " << i << endl;
//			cout << "Number Order is: " << i + 1 << endl;
//		}
//		else if (arr[i] != NumberToFind && i == ArrayLength - 1)
//			cout << "The Number " << NumberToFind << " is Not Found in The Array :( " << endl;
//
//	}
//
//}

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


int main()
{
	srand((unsigned)time(NULL));

	int ArrayLength = ReadPositiveNumber("Enter Array Length:");
	int arr[100];

	FillArrayWithRandomNumbers(ArrayLength, arr);
	cout << "Array Elements: \n";
	PrintArray(ArrayLength, arr);

	//LocateNumberInArray(ArrayLength, arr, ReadPositiveNumber("\n\nPLease Enter The Number You Are Looking For:"));

	int NumberToFind = ReadPositiveNumber("\n\nEnter The Number To Find");
	cout << "\n\nThe Number You are Looking For is " << NumberToFind;

	int NumberPosition = FindNumberPositionInArray(ArrayLength, arr, NumberToFind);

	if (NumberPosition == -1)
		cout << "\nThe Number " << NumberToFind << " is Not Found in The Array :( " << endl;
	else
	{
		cout << "\n\nThe number found at position: " << NumberPosition << endl;
		cout << "The number found its order  : " << NumberPosition + 1 << endl;
	}


	

	cout << endl << endl;
	return 0;
}
