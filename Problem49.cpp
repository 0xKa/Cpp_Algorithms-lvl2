// creating Ceiling Function 

#include <iostream>
using namespace std;

float ReadNumber(string massage)
{
	float num;
	cout << massage;
	cin >> num;
	cout << endl;

	return num;
}

float GetFractionPart(float num)
{
	return num - int(num);
}

int MyCeil(float num)
{
	if (num > 0) {
		if (GetFractionPart(num) != 0)
			return int(num) + 1;
		else
			return num;
	}
	else
		return int(num);
}


int main()
{
	float number = ReadNumber("Enter Number: ");


	cout << "MyCeil Function Result: " << MyCeil(number) << endl;
	cout << "C++ Ceil Function Result: " << ceil(number) << endl;

	return 0;
}

