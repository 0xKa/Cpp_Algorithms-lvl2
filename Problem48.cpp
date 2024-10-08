//making floor function 

#include <iostream>
using namespace std;

float ReadNumber(string massage)
{
    int num;
    cout << massage;
    cin >> num;
    cout << endl;

    return num;
}

int MyFloor(float num)
{
    if (num > 0)
        return (int)num;
    else
        return (int)num - 1;

}

int main()
{
    
    float number = ReadNumber("Enter Number: ");

    cout << "MyFloor Function Result: " << MyFloor(number) << endl;
    cout << "C++ floor Function Result: " << floor(number) << endl; // what is wrong with c++ function? :/





    cout << endl;
    return 0;
}

