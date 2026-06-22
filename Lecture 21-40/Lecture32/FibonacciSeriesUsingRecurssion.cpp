// -----------------------------------------------------------------------------
// Learning focus: Fibonacci Series Using Recursion
// Purpose: Generates or calculates Fibonacci Series Using Recursion.
// Core idea: Each term is formed from the two preceding terms; recursive versions directly mirror this recurrence.
// Complexity note: The iterative version is O(n); naive recursion is exponential and uses O(n) stack depth.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/fibonacci-number/description/
#include <bits/stdc++.h>
using namespace std;

int getNthFibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return getNthFibonacci(n - 1) + getNthFibonacci(n - 2);
}
int main()
{
    int input;
    cout << "Enter a number to get fibonacci of that position: ";
    cin >> input;
    int result = getNthFibonacci(input);
    cout << "Result: " << result << endl;
}