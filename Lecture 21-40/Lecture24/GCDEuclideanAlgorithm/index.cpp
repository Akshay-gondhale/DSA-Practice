// -----------------------------------------------------------------------------
// Learning focus: GCDEuclidean Algorithm
// Purpose: Computes the greatest common divisor with Euclid's algorithm.
// Core idea: Repeatedly replace the larger problem with the remainder problem because gcd(a, b) equals gcd(b, a mod b).
// Complexity note: Time is O(log(min(a, b))) and iterative extra space is O(1).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
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