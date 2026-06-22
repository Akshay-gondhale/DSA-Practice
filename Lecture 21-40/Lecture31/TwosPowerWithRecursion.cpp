// -----------------------------------------------------------------------------
// Learning focus: Twos Power With Recursion
// Purpose: Demonstrates Twos Power With Recursion through recursion.
// Core idea: A base case handles the smallest input; each recursive call reduces the problem and the returning calls combine or print results.
// Complexity note: Recursion depth and time follow the amount by which each call reduces the input.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Computes a power recursively by reducing the exponent toward its base case.
int getTwosPower(int n)
{
    // Key idea: The base case stops recursion; each returning call contributes the current multiplication.
    if (n <= 1)
    {
        return 2;
    }
    return 2 * getTwosPower(n - 1);
}
int main()
{
    int power;
    cout << "Enter a power number for 2: ";
    cin >> power;
    int result = getTwosPower(power);
    cout << "2s power " << power << " is " << result << endl;
}
