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