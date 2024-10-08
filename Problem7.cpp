// print the number in reverse

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

int ReverseTheNumber(int num)
{
	int remainder = 0;
	string result;
	
	
	while (num > 0)
	{
		remainder = num % 10;
		result = result + to_string(remainder);
		num = floor(num / 10);
	}
	return stoi(result);
}

// Mohammed Abo Hadhood Solution
int ReverseTheNumber2(int num) // Mohammed Abo Hadhood Solution
{
	int remainder = 0;
	int num2 = 0;
	
	
	while (num > 0)
	{
		remainder = num % 10;
		num = floor(num / 10);
		
		num2 = num2 * 10 + remainder;
	
	
	}
	return num2;
}


int main()
{


	cout << "The Remainder is : \n" << ReverseTheNumber(ReadPositiveNumber("Enter Positive Number: "));




	return 0;
}

