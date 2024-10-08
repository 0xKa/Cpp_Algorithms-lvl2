//digit frequency

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
			f_counter++;

	}
	return f_counter;
}


void PrintDigitFrequencyForAllNumbers(double double num)
{
	for (short i = 0; i < 10; i++)
	{
		short DigitFrequency = CountDigitFrequency(num, i);

		if (DigitFrequency > 0)
			cout << "Digit \"" << i << "\" Frequency is : " << DigitFrequency << " Time(s)" << endl;
	}

}

int main()
{
	

	PrintDigitFrequencyForAllNumbers(ReadPositiveNumber("Enter Positive Number"));

	cout << endl << endl;
	return 0;
}
