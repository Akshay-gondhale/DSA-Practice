// -----------------------------------------------------------------------------
// Learning focus: Factorial With Recursion
// Purpose: Calculates factorial recursively.
// Core idea: The base case stops at 0 or 1; each larger call multiplies its value by the result of the smaller subproblem.
// Complexity note: Time and recursive stack space are both O(n).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int factorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}
int main()
{
    int num;
    cout << "Enter an number to get factorial: ";
    cin >> num;
    int result = factorial(num);
    cout << num << "! = " << result << endl;
}