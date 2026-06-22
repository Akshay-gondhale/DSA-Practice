// -----------------------------------------------------------------------------
// Learning focus: Right And Left Shift Operator
// Purpose: Demonstrates Right And Left Shift Operator using place values or bitwise operations.
// Core idea: Process one digit or bit at a time, updating the accumulated result and moving to the next place.
// Complexity note: Time is proportional to the number of digits/bits; extra space is O(1).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// Right and left shift operators are used to shift bits left and right by given number
// variable >> 2  ==> so this will shift bit by right
#include <iostream>
using namespace std;

int main()
{
    // This will result in 1
    // explaination:
    // 2 -> 10 in binary
    // so last digit got removed as we are doing right shift and only 1 left
    // so 1 in binary is 1
    cout << (2 >> 1) << endl;

    // This will result in 4
    // explaination:
    // 2 -> 10 in binary
    // so 0 got added in last digit as we are doing left shift and it became 100
    // so 4 in binary is 100
    cout << (2 << 1) << endl;
}