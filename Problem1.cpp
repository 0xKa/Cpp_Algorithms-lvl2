// a program that print the Multiplication Table (1 to 14)

#include <iostream>
using namespace std;

void PrintTableHeader()
{
	cout << "\n\n\t\t\t\t\t\tMultiplication Table\n\n\t";
	for (int i = 1; i <= 5; i++)
	{
		cout  << i << "\t";
	}
	cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
}

string ColumnSperator(int i)
{
	if (i < 10)
		return "    | ";
	else
		return "   | ";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();
	
	for (int i = 1; i <= 5; i++)
	{
		cout << " " << i << ColumnSperator(i);
		for (int j = 1; j <= 5; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}

}


int main()
{
	PrintMultiplicationTable();

	cout << endl << endl;
	return 0;
}