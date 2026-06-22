// -----------------------------------------------------------------------------
// Learning focus: For Loop
// Purpose: Introduces the C++ fundamentals used in For Loop.
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
    for (int i = 0; i < input; i++)
    {
        cout << "*" << endl;
    }
}
