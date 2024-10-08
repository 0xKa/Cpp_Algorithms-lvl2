//print Frequency of number/digit

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

int CountDigitFrequency(int num, short digit)
{
	int f_counter = 0, remainder = 0;

	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		if (remainder == digit)
		{
			f_counter++;
		}

	}


	return f_counter;


}


int main()
{
	int Number = ReadPositiveNumber("Enter a Positive Number: ");
	short Digit = ReadPositiveNumber("Enter a The Digit Number: ");
	
	cout << "\nDigit \""<< Digit << "\" Frequency is " << CountDigitFrequency(Number, Digit) << " Time(s).";
	

	cout << endl << endl;
	return 0;
}

