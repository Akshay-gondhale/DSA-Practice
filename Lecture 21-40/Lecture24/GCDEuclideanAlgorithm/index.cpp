// -----------------------------------------------------------------------------
// Learning focus: GCDEuclidean Algorithm
// Purpose: Computes the greatest common divisor with Euclid's algorithm.
// Core idea: Repeatedly replace the larger problem with the remainder problem because gcd(a, b) equals gcd(b, a mod b).
// Complexity note: Time is O(log(min(a, b))) and iterative extra space is O(1).
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// Computes the greatest common divisor using Euclid's remainder reduction.
int gcd(int a, int b)
{
    // Key idea: Replacing (a, b) with (b, a mod b) preserves the GCD while shrinking the problem.
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int main()
{
    int a, b;
    cout << "Enter first number a: ";
    cin >> a;

    cout << "Enter second number b: ";
    cin >> b;

    int result = gcd(a, b);
    cout << "GCD of " << a << ", " << b << " is " << result << endl;
}
