// -----------------------------------------------------------------------------
// Learning focus: Conditions
// Purpose: Introduces the C++ fundamentals used in Conditions.
// Core idea: Read execution from top to bottom and observe how declarations, conditions, loops, and output statements change program flow.
// Complexity note: This is a language-feature demonstration; complexity is secondary to control flow.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
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