// -----------------------------------------------------------------------------
// Learning focus: Do While Loop
// Purpose: Introduces the C++ fundamentals used in Do While Loop.
// Core idea: Read execution from top to bottom and observe how declarations, conditions, loops, and output statements change program flow.
// Complexity note: This is a language-feature demonstration; complexity is secondary to control flow.
// -----------------------------------------------------------------------------
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
