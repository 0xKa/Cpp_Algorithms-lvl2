//

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

void PrintNormalLetterPattern(int num)
{
	cout << endl;
	// 65 = A and so on 

	for (int i = (1 + 64); i <= (num + 64); i++)
	{
		for (int j = 1; j <= (i - 64); j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}

int main()
{
	PrintNormalLetterPattern(ReadPositiveNumber("Enter Number:"));



	cout << endl << endl;
	return 0;
}
