// -----------------------------------------------------------------------------
// Learning focus: Prime Number
// Purpose: Checks whether an input number is prime.
// Core idea: Test possible divisors and reject the number as soon as an exact divisor is found.
// Complexity note: The shown loop determines whether this is O(n) or the optimized O(sqrt(n)) approach.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number to check prime: ";
    cin >> n;
    // Key idea: A number is composite as soon as any tested divisor divides it exactly; no later divisor can make it prime again.
    if (n <= 2)
    {
        cout << n << " is prime number" << endl;
    }
    else
    {
        bool isPrime = true;
        for (int i = 2; i < n / 2 + 1; i++)
        {
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            cout << n << " is a prime number" << endl;
        }
        else
        {
            cout << n << " is not a prime number" << endl;
        }
    }
}
