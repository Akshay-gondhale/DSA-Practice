// -----------------------------------------------------------------------------
// Learning focus: pointers With Char Array
// Purpose: Explores pointers With Char Array and how C++ accesses objects through addresses or aliases.
// Core idea: Track both the stored address and the value reached by dereferencing; note when a function receives a copy versus an address/reference.
// Complexity note: These examples emphasize memory semantics rather than algorithmic complexity.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    // this prints address of arr
    cout << "Address of arr: " << arr << endl;
    // attention here
    // cout function is implemented differnet for char array. If char pointer passed to cout it prints entire character until it finds \0 null character;
    cout << "Entire char array: " << ch << endl;
    cout << endl;
    // creating different pointer and printing array from it
    char *charPointer = &ch[0];
    cout << "Print char array from another pointer: " << charPointer << endl;
    cout << endl;
    // what if there is no \0 character??
    // cout function prints until it find out \0 pointer in garbage memory.
    char temp = 'z';
    char *p = &temp;
    cout << "Printing char array pointer until it finds null pointer: " << p << endl;
}
