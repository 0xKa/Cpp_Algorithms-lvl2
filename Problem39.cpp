// copy Prime numbers only from array using AddArrayElement function
#include <iostream>
using namespace std;

//enum enPrimNotPrime{ Prime = 1, NotPrime = 2 };
//enPrimNotPrime CheckPrime(int Number) {
//	int M = round(Number / 2);
//	for (int Counter = 2; Counter <= M; Counter++)
//	{
//		if (Number % Counter == 0) 
//			return enPrimNotPrime::NotPrime;
//	}
//	return enPrimNotPrime::Prime;
//}              ////ABO HADHOUD FUNCTION

bool isPrime(int num)
{
	int m = round(num / 2);
	for (int i = 2; i <= m; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
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

void CopyPrimeNumberFromArray(int arrSource[100], int arrDestination[100], int arrSourceLength, int& arrDestinationLength)//using AddArrayElement function
{
	for (int i = 0; i < arrSourceLength; i++)
	{
		if (isPrime(arrSource[i]) == true)
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



	CopyPrimeNumberFromArray(arr, arr2, arrLength, arr2Length);
	cout << "Array 2 Elements: ";
	PrintArray(arr2, arr2Length);


	return 0;
}