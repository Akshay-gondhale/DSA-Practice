// -----------------------------------------------------------------------------
// Learning focus: Sum From One To N
// Purpose: Introduces the C++ fundamentals used in Sum From One To N.
// Core idea: Read execution from top to bottom and observe how declarations, conditions, loops, and output statements change program flow.
// Complexity note: This is a language-feature demonstration; complexity is secondary to control flow.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter an number: ";
    cin >> num;
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += i;
    }
    cout << "Total sum is: " << sum << endl;
}