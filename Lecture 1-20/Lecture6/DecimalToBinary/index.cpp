// -----------------------------------------------------------------------------
// Learning focus: Decimal To Binary
// Purpose: Demonstrates Decimal To Binary using place values or bitwise operations.
// Core idea: Process one digit or bit at a time, updating the accumulated result and moving to the next place.
// Complexity note: Time is proportional to the number of digits/bits; extra space is O(1).
// -----------------------------------------------------------------------------
// This program converts decimal to binary
// it only accepts positive number as of now
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    cout << "Enter a number: ";
    int num;
    cin >> num;

    int i = 0;
    int ans = 0;

    // Key idea: Repeated division by two produces bits from least significant to most significant, so place value is tracked explicitly.
    while (num != 0)
    {
        int bit = num & 1;
        ans = (bit * pow(10, i)) + ans;
        num = num >> 1;
        i++;
    }
    cout << ans << endl;
}
