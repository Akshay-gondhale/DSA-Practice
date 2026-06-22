// -----------------------------------------------------------------------------
// Learning focus: Double Pointers In Functions
// Purpose: Explores Double Pointers In Functions and how C++ accesses objects through addresses or aliases.
// Core idea: Track both the stored address and the value reached by dereferencing; note when a function receives a copy versus an address/reference.
// Complexity note: These examples emphasize memory semantics rather than algorithmic complexity.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void testingPointers(int **p)
{
    // this will not change anything
    // p = p + 1;
    // cout << "Inside function p value: " << p << endl;

    // this will change pointer 1's address but value will remain same
    *p = *p + 1;
    cout << "Inside function *p value: " << *p << endl;

    // this will update value
    // **p = **p + 1;
    // cout << "Inside function **p value: " << **p << endl;
    cout << endl;
}
int main()
{
    int num = 5;
    int *p1 = &num;
    int **p2 = &p1;
    cout << "Before num: " << num << endl;
    cout << "Before p1: " << p1 << endl;
    cout << "Before p2: " << p2 << endl;
    cout << endl;
    testingPointers(p2);
    cout << "After num: " << num << endl;
    cout << "After p1: " << p1 << endl;
    cout << "After p2: " << p2 << endl;
    cout << endl;
}