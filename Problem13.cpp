//normal number pattern

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

void PrintNormalNumberPattern(int num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}

int main()
{
	PrintNormalNumberPattern(ReadPositiveNumber("Enter Positive Number: "));
	cout << endl << endl;
	return 0;
}
