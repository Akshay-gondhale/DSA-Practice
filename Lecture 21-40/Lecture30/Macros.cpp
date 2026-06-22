// -----------------------------------------------------------------------------
// Learning focus: Macros
// Purpose: Demonstrates the C++ language feature Macros.
// Core idea: Compare what the compiler or preprocessor supplies automatically with values and calls written explicitly by the programmer.
// Complexity note: The focus is compile-time substitution and function-call semantics, not data-size complexity.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// macros are besically defined using #define
// They dont need data type and semicolon
// also this are like constant global variables which cannot be modified during run time.
// here compiler will replace all appearances of MACROVARIABLE with 30 before compiling.
#define MACROVARIABLE 30
int main()
{
    int test = MACROVARIABLE * 10;
    cout << test << endl;
}