// sum of digits
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

int CalculateSumOfDigits(int num)
{
	int remainder = 0;
	int sum = 0;

	while (num > 0)
	{
		remainder = num % 10;
		num = floor(num / 10);
		sum = sum + remainder;
	}
	return sum;
}



int main()
{
 
	cout << "\nThe Sum of All Digits is : " << CalculateSumOfDigits(ReadPositiveNumber("Enter posistive number")) << endl;


	return 0;
}