// -----------------------------------------------------------------------------
// Learning focus: 1009: Complement Of Base10
// Purpose: Demonstrates 1009: Complement Of Base10 using place values or bitwise operations.
// Core idea: Process one digit or bit at a time, updating the accumulated result and moving to the next place.
// Complexity note: Time is proportional to the number of digits/bits; extra space is O(1).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/complement-of-base-10-integer/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int ans = ~num;
    int mask = 0;
    while (num != 0)
    {
        num = num >> 1;
        mask = mask << 1;
        mask = mask | 1;
    }

    ans = ans & mask;
    cout << ans;
}