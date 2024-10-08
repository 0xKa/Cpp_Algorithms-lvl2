//inverted number pattern

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

void PrintInvertedPatternNumber(int num)
{
	for(int i = 0; i < num ; num--)
	{

		for (int j = 0; j < num; j++)
			{
			cout << num;
			}

		cout << endl;

	}
}

// Mohammed Abo Hadhood Solution
void PrintInvertedPatternNumber2(int num) // Mohammed Abo Hadhood Solution
{
	for (int i = num; i > 0; i--)
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
	PrintInvertedPatternNumber(ReadPositiveNumber("Enter Positive Number: "));
	cout << endl << endl;
	return 0;
}
