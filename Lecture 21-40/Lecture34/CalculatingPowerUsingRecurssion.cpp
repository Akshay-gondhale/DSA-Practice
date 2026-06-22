// -----------------------------------------------------------------------------
// Learning focus: Calculating Power Using Recursion
// Purpose: Computes a power using Calculating Power Using Recursion and exponent decomposition.
// Core idea: Halve the exponent, reuse the half-power, square it, and multiply once more when the exponent is odd.
// Complexity note: Time is O(log exponent); recursive code uses O(log exponent) stack space.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// unoptimised
// int calculatePower(int num, int power)
// {
//     if (power == 0)
//     {
//         return 1;
//     }
//     if (power == 1)
//     {
//         return num;
//     }
//     return num * calculatePower(num, power - 1);
// }

// Optimized recursive exponentiation: solve one half-sized subproblem and reuse
// its result instead of making two identical recursive calls.
int calculatePower(int num, int power)
{
    // Key idea: The base case stops recursion; each returning call contributes the current multiplication.
    if (power == 0)
    {
        return 1;
    }
    if (power == 1)
    {
        return num;
    }
    int ans = calculatePower(num, power / 2);
    if (power % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return num * ans * ans;
    }
}
int main()
{
    int num = 5;
    int power = 2;
    int result = calculatePower(num, power);
    cout << result << endl;
}
