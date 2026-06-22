// -----------------------------------------------------------------------------
// Learning focus: Fast Exponential
// Purpose: Computes a power using Fast Exponential and exponent decomposition.
// Core idea: Halve the exponent, reuse the half-power, square it, and multiply once more when the exponent is odd.
// Complexity note: Time is O(log exponent); recursive code uses O(log exponent) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            // odd
            res = (1LL * (res) * (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;
    }
    return res;
}
int main()
{
    int result = modularExponentiation(4, 3, 10);
    cout << result << endl;
}