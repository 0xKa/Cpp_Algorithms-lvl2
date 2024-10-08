// check perfect num from 1 to N
#include <iostream>
using namespace std;

int ReadPositiveNumber(string massage)
{
    int num;
    do
    {
        cout << massage << endl;
        cin >> num;
    } while (num <= 0);
    return num;
}

bool CheckIfPerfect(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
            sum += i;

    }

    return (sum == num); // it will return true or false
}

void PrintPerfectNumbersFrom1toN(int num)
{
    cout << "\nThe Perfect Numbers from " << 1 << " to " << num << " Are:\n";
    for (int counter = 1; counter < num; counter++)
    {
        if (CheckIfPerfect(counter))
            cout << counter << endl;
    }
}

int main()
{


    PrintPerfectNumbersFrom1toN(ReadPositiveNumber("Enter Positive Number: "));


	cout << endl;
	return 0;
}
