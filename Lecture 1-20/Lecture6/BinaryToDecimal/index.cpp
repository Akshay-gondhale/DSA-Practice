// -----------------------------------------------------------------------------
// Learning focus: Binary To Decimal
// Purpose: Demonstrates Binary To Decimal using place values or bitwise operations.
// Core idea: Process one digit or bit at a time, updating the accumulated result and moving to the next place.
// Complexity note: Time is proportional to the number of digits/bits; extra space is O(1).
// -----------------------------------------------------------------------------
// this convert binary number to decimal
// eg: 1010 -> 10
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter a binary number: ";
    cin >> num;
    int i = 0;
    int ans = 0;
    // Key idea: Each extracted binary digit contributes digit * 2^position to the decimal result.
    while (num > 0)
    {
        int digit;
        digit = num % 10;
        if (digit == 1)
        {
            ans += pow(2, i);
        }
        i++;
        num = num / 10;
    }
    cout << "Number is: " << ans << endl;
}
