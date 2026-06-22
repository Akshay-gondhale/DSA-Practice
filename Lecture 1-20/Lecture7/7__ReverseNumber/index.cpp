// -----------------------------------------------------------------------------
// Learning focus: 7: Reverse Number
// Purpose: Demonstrates 7: Reverse Number using place values or bitwise operations.
// Core idea: Process one digit or bit at a time, updating the accumulated result and moving to the next place.
// Complexity note: Time is proportional to the number of digits/bits; extra space is O(1).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/reverse-integer/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number to reverse: ";
    cin >> num;
    int ans = 0;
    while (num != 0)
    {
        ans = ans * 10;
        int digit = num % 10;
        cout << "digit: " << digit << endl;
        num = num / 10;
        ans += digit;
    }
    cout << ans << endl;
}