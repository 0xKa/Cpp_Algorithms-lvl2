// Creating MySqrt Function

#include <iostream>
using namespace std;

float ReadNumber()
{
	float num;
	cout << "Enter a Number: ";
	cin >> num;

	return num;
}

float MySqrt(float num)
{
	return pow(num, 0.5);
}

int main()
{

	float number = ReadNumber();

	cout << "MySqurt Function Result: " << MySqrt(number) << endl;
	cout << "C++ squrt Function Result: " << sqrt(number) << endl;




	return 0;
}

