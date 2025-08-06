#include <iostream>
using namespace std;

int main()
{
    int input;
    cout << "Enter a number: ";
    cin >> input;
    if (input > 0)
    {
        cout << input << " is a positive number" << endl;
    }
    else if (input < 0)
    {
        cout << input << " is a negative number" << endl;
    }
    else
    {
        cout << input << " is zero" << endl;
    }
}