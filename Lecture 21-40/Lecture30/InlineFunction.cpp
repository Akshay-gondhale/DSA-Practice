// -----------------------------------------------------------------------------
// Learning focus: Inline Function
// Purpose: Introduces the C++ fundamentals used in Inline Function.
// Core idea: Read execution from top to bottom and observe how declarations, conditions, loops, and output statements change program flow.
// Complexity note: This is a language-feature demonstration; complexity is secondary to control flow.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// if your function haves only 1 line then you can convert it to inline function.
// compiler its occurance too with single line code before compilation
inline int getMax(int &a, int &b) { return (a > b) ? a : b; }
int main()
{
    int a = 4, b = 5;
    int ans = getMax(a, b);
    cout << ans << endl;
}