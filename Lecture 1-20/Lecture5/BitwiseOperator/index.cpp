// -----------------------------------------------------------------------------
// Learning focus: Bitwise Operator
// Purpose: Demonstrates Bitwise Operator using place values or bitwise operations.
// Core idea: Process one digit or bit at a time, updating the accumulated result and moving to the next place.
// Complexity note: Time is proportional to the number of digits/bits; extra space is O(1).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// and = &
// or = |
// not = ~
// xor = ^
#include <iostream>
using namespace std;

int main()
{
    // and operator
    int a = 4;                               // 100
    int b = 6;                               // 110
    cout << "And a&b = " << (a & b) << endl; // and = 100
    cout << "Or a|b = " << (a | b) << endl;  // or = 110
    cout << "Not ~a = " << ~a << endl;       // not = 011
    cout << "XOR a^b = " << (a ^ b) << endl; // or = 010
}