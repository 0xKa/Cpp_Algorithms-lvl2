// print AAA to ZZZ

#include <iostream>
using namespace std;


void PrintAAAtoZZZ()
{
	string word = "";

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int o = 65; o <= 90; o++)
			{

				word = word + char(i);
				word = word + char(j);
				word = word + char(o);

				cout << word << endl;

				word = "";
			}
		}
	}
}

int main()
{
	PrintAAAtoZZZ();

	cout << endl << endl;
	return 0;
}
