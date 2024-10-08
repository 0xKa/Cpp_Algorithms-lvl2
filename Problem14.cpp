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

void PrintInvertedLetterPattern(int num)
{
	// 65 = A and so on 
	for (int i = (num + 64); i >= (64); i--)
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
	PrintInvertedLetterPattern(ReadPositiveNumber("Enter Number:"));



	cout << endl << endl;
	return 0;
}
