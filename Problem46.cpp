// absolute function
#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber(string massage)
{
	int num;
	cout << massage;
	cin >> num;
	return num;
}

int MyABS(int number)
{
	if (number > 0)
		return number;
	else
		return -number;
}

int main()
{

	int number = ReadNumber("Enter Number: ");

	cout << "My Absolute Result = " << MyABS(number) << endl;
	cout << "C++ Absolute Result = " << abs(number) << endl;

	return 0;
}