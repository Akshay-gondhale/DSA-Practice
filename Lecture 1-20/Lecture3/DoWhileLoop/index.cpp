#include <iostream>
using namespace std;
int main()
{
    int input;
    cout << "Enter a number: ";
    cin >> input;
    if (input < 0)
    {
        cout << "Please enter a positive number";
    }
    else
    {
        int start = 0;
        do
        {
            cout << "*" << endl;
            start++;
        } while (start < input);
    }
}