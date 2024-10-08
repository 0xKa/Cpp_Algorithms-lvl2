//guess a 3 letter password

#include <iostream>
using namespace std;

string ReadPassword(string massage)
{
	string password;
	cout << massage << endl;
	cin >> password;

	return password;
	
}

bool GuessPassword(string password)
{
	
	string word = "";
	int counter = 0;
	
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				counter++;

				word = word + char(i) + char(j) + char(k);

				cout << "\nTrial [" << counter << "] : " << word << endl;

				if (word == password)
				{
					cout << "\n*****************************************\n";
					cout << "\nPassword is : " << word << endl;
					cout << "\nFound After " << counter << " Trial(s)\n";
					return true;
				}
				
				word = "";

			}
	
		}

	}
	cout << "\n*****************************************\n\n";
	cout << "Password Not Found";
	return false;
}

int main()
{
	GuessPassword(ReadPassword("Enter a 3 Capital letter Password:"));

	cout << endl << endl;
	return 0;
}
