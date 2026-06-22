// -----------------------------------------------------------------------------
// Learning focus: Say Digits
// Purpose: Demonstrates Say Digits through recursion.
// Core idea: A base case handles the smallest input; each recursive call reduces the problem and the returning calls combine or print results.
// Complexity note: Recursion depth and time follow the amount by which each call reduces the input.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void sayDigit(int n)
{
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