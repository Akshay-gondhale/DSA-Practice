// -----------------------------------------------------------------------------
// Learning focus: Say Digits
// Purpose: Demonstrates Say Digits through recursion.
// Core idea: A base case handles the smallest input; each recursive call reduces the problem and the returning calls combine or print results.
// Complexity note: Recursion depth and time follow the amount by which each call reduces the input.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Prints a number in words recursively, preserving left-to-right digit order.
void sayDigit(int n)
{
    // Key idea: Recurse on n/10 before printing n%10 so the most significant digit is emitted first.
    if (n == 0)
    {
        return;
    }
    string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigit(n / 10);
    int lastDigit = n % 10;
    cout << numbers[lastDigit] << " ";
}
int main()
{
    sayDigit(506);
}
