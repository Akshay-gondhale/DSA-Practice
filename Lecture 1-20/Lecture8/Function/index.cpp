// -----------------------------------------------------------------------------
// Learning focus: Function
// Purpose: Introduces the C++ fundamentals used in Function.
// Core idea: Read execution from top to bottom and observe how declarations, conditions, loops, and output statements change program flow.
// Complexity note: This is a language-feature demonstration; complexity is secondary to control flow.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// nCr formula with functions
// Formula:
// nCr = n!/r!(n-r)!

#include <iostream>
using namespace std;
int factorial(int num)
{
    int ans = 1;
    for (int i = num; i > 0; i--)
    {
        ans = ans * i;
    }
    return ans;
}
int ncrFormula(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int main()
{
    cout << ncrFormula(3, 2) << endl;
}