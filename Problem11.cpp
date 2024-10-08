//check if palindrome number

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

int ReverseTheNumber(int num)
{
	int remainder = 0;
	int reversedNum = 0;

	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		reversedNum = reversedNum * 10 + remainder;
	}

	return reversedNum;
}

bool IsPlaindromeNumber(int num)
{
		return (num == ReverseTheNumber(num));
}


int main()
{
	if (IsPlaindromeNumber(ReadPositiveNumber("Enter a Positive Number: ")))
		cout << "It is a Plaindrome Number!!";
	else
		cout << "It is NOT a PLaindrome Number!!";


	cout << endl << endl;
	return 0;
}
