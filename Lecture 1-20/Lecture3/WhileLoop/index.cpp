#include <iostream>
using namespace std;
int main()
{
    int input;
    cout << "Enter a number: " << endl;
    cin >> input;
    if (input < 0)
    {
        cout << "Please enter a positive number";
    }
    else
    {
        int start = 0;
        while (start < input)
        {
            cout << "*" << endl;
            start++;
        }
    }
}