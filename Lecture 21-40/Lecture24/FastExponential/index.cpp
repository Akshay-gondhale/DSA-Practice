// -----------------------------------------------------------------------------
// Learning focus: Fast Exponential
// Purpose: Computes a power using Fast Exponential and exponent decomposition.
// Core idea: Halve the exponent, reuse the half-power, square it, and multiply once more when the exponent is odd.
// Complexity note: Time is O(log exponent); recursive code uses O(log exponent) stack space.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Computes (x^n) mod m with exponentiation by squaring, avoiding construction of the enormous raw power.
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int res = 1;
    // Key idea: Each step halves the exponent; an odd exponent contributes one additional factor of x.
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
