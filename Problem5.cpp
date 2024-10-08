// print digits in reversed order

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

void PrintDigits(int num)
{
	int remainder = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num = floor(num / 10); // the floor function doesn't matter because the variable/parameter is [int]
		cout << remainder << endl;
	}
}

int main()
{
	PrintDigits(ReadPositiveNumber("Enter Positive Number"));
	cout << endl;
	return 0;
}

