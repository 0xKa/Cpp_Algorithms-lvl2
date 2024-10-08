//My Round Function

#include <iostream>
using namespace std;

float ReadNumber(string massage)
{
	float num;

	cout << massage;
	cin >> num;


	return num;
}

float GetFractionPart(float num)
{
	return num - (int)num;
}

int MyRound(float number)
{
	int IntPart = (int)number;
	float FractionPart = GetFractionPart(number);

	if (abs(FractionPart) >= 0.5)
	{
		if (number > 0)
			return IntPart + 1;
		else
			return IntPart - 1;
	}
	else
		return IntPart;

}

int MyRound2(float number)
{
	float temp = number * 10;
	float remainder = (int)temp % 10;
	if (abs(remainder) >= 5)
	{
		if (number > 0)
			return number + 1;
		else
			return number - 1;
	}
	else
		return number;

}

int main()
{
	float number = ReadNumber("Enter Number: ");

	cout << "MyRound Result = " << MyRound(number) << endl;
	cout << "MyRound2 Result = " << MyRound2(number) << endl;
	cout << "C++ Round Result = " << round(number) << endl;



	cout << endl << endl;
	return 0;
}

