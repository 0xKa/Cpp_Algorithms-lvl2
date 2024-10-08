//print all prime numbers (1 to N)
#include <iostream>
using namespace std;

enum enNumberType { Prime = 1, NotPrime = 2 };

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

enNumberType CheckNumberType(int num)
{
	int M = round(num / 2);
	for (int counter = 2; counter <= M; counter++)
	{
		if (num % counter == 0)
			return NotPrime;
	}
	return Prime;

}

void PrintPrimeNumbers(int num)
{
	cout << "\nPrime Numbers From 1 to " << num << " Are: \n";

	for (int i = 1; i <= num; i++)
	{
		if (CheckNumberType(i) == Prime)
			cout << i << endl;
	}
}

int main()
{
	PrintPrimeNumbers(ReadPositiveNumber("Enter a positive number : "));

	cout << endl;
	return 0;
}


