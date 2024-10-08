//Random letters, Special char, digits

#include <iostream>
using namespace std;

enum enumCharType {SmallLetter = 1,CapitalLetter = 2, SpecialChar = 3, Digit = 4};

int RandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
}

char PrintRandomCharType(enumCharType chartype)
{
	// not necessery to use char()
	switch (chartype) {
	case (SmallLetter):
		return char(RandomNumber(97, 122));
	case (CapitalLetter):
		return char(RandomNumber(65, 90));
	case (SpecialChar):
		return char(RandomNumber(33, 47));
	case(Digit):
		return char(RandomNumber(48, 57));
	
	}

}



int main()
{
	srand((unsigned)time(NULL));

	cout << PrintRandomCharType(SmallLetter) << endl;
	cout << PrintRandomCharType(CapitalLetter) << endl;
	cout << PrintRandomCharType(SpecialChar) << endl;
	cout << PrintRandomCharType(Digit) << endl;

	cout << endl << endl;
	return 0;
}
