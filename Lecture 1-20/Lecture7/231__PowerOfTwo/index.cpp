// -----------------------------------------------------------------------------
// Learning focus: 231: Power Of Two
// Purpose: Demonstrates 231: Power Of Two using place values or bitwise operations.
// Core idea: Process one digit or bit at a time, updating the accumulated result and moving to the next place.
// Complexity note: Time is proportional to the number of digits/bits; extra space is O(1).
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/power-of-two/submissions/1791445319/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    int i = 0;
    bool isPowerOfTwo = false;

    // Key idea: A positive power of two has exactly one set bit; equivalent implementations may test this through bits or repeated division.
    while (i < 32)
    {
        int power = pow(2, i);
        if (power > num)
        {
            break;
        }
        if (power == num)
        {
            isPowerOfTwo = true;
            break;
        }
        i++;
    }
    cout << isPowerOfTwo << endl;
}
