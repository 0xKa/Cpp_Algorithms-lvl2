//random numbers from 1 to 10

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
}


int main()
{

	srand((unsigned)time(NULL));

	cout << RandomNumber(1,999);

	cout << endl << endl;
	return 0;
}
