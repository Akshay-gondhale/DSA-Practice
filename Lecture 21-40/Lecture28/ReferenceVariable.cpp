// -----------------------------------------------------------------------------
// Learning focus: Reference Variable
// Purpose: Explores Reference Variable and how C++ accesses objects through addresses or aliases.
// Core idea: Track both the stored address and the value reached by dereferencing; note when a function receives a copy versus an address/reference.
// Complexity note: These examples emphasize memory semantics rather than algorithmic complexity.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void update(int &n)
{
    n++;
}
int main()
{
    // reference variable are those who share same memory address but have different names
    int i = 5;
    int &j = i;
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    i++;
    cout << "i after i++ = " << i << endl;
    cout << "j after i++ = " << j << endl;
    j++;
    cout << "i after j++ = " << i << endl;
    cout << "j after j++ = " << j << endl;
    cout << endl;
    cout << endl;
    // mostly this gets used in functions to pass a value by reference.
    // eg :
    // void update(int &n){
    //     n ++;
    // }
    // this will update the main variable directly.
    int num = 5;
    cout << "Before num: " << num << endl;
    update(num);
    cout << "After num: " << num << endl;
}