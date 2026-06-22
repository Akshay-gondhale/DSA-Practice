// -----------------------------------------------------------------------------
// Learning focus: Default Arguments
// Purpose: Demonstrates the C++ language feature Default Arguments.
// Core idea: Compare what the compiler or preprocessor supplies automatically with values and calls written explicitly by the programmer.
// Complexity note: The focus is compile-time substitution and function-call semantics, not data-size complexity.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// here start is an default argument if nothing passed it will take 0
void printArray(int arr[], int size, int start = 0)
{
    for (int i = start; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printArray(arr, 5, 3);
}
