// -----------------------------------------------------------------------------
// Learning focus: Factorial With Recursion
// Purpose: Calculates factorial recursively.
// Core idea: The base case stops at 0 or 1; each larger call multiplies its value by the result of the smaller subproblem.
// Complexity note: Time and recursive stack space are both O(n).
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Returns n! by multiplying n with the factorial of the smaller subproblem n-1.
int factorial(int num)
{
    // Key idea: The base case returns 1 and prevents the recursive chain from continuing indefinitely.
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
