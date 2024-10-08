//a program that check if the number is perfect
 
//[a perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. For instance, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6, so 6 is a perfect number. (1 + 2 + 4 + 7 + 14 = 28)]


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

void PrintResult(int num)
{
    if (CheckIfPerfect(num))
        cout << "The Number " << num << " is Perfect";
    else
        cout << "The Number " << num << " is Not Perfect";
}

int main()
{
    PrintResult(ReadPositiveNumber("Please Enter a Positive Number :"));


    cout << endl;
    return 0;
}

