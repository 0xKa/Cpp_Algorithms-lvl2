//print digits in order

#include <iostream>
#include <string>
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

int RverseTheNumber(int num)
{
	int remainder = 0;
	int ReversedNum = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		
		ReversedNum = ReversedNum * 10 + remainder;
	}
	return (ReversedNum);
}

void PrintDigits(int num)
{
	int remainder = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		cout << remainder << endl;
	}
}

int main()
{

	PrintDigits(RverseTheNumber(ReadPositiveNumber("Enter Number: ")));

	cout << endl << endl;
	return 0;
}
