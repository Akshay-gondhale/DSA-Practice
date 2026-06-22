// -----------------------------------------------------------------------------
// Learning focus: pointers With Functions
// Purpose: Explores pointers With Functions and how C++ accesses objects through addresses or aliases.
// Core idea: Track both the stored address and the value reached by dereferencing; note when a function receives a copy versus an address/reference.
// Complexity note: These examples emphasize memory semantics rather than algorithmic complexity.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void print(int *p)
{
    cout << "Value of pointer in function is: " << *p << endl;
}

// Demonstrates whether changes made through this parameter are visible to the caller.
void update(int *p)
{
    // if we update pointer address it will not affect main.
    // p = p + 1;
    // cout << "inside "<< p <<endl;
    // but if we update its value then it will modify main value
    *p = *p + 1;
}

// Sums an array received as a pointer, illustrating that array parameters do not retain compile-time length information.
int getSum(int *arr, int n)
{

    // this prints size of pointer as 8
    // cout << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int value = 5;
    int *p = &value;
    print(p);
    cout << endl;
    cout << "Checking if updating pointer value in function can change is address?" << endl;
    cout << "Before: " << *p << endl;
    update(p);
    cout << "After: " << *p << endl;
    cout << endl;
    // printing array sum from middle of array using pointers

    int arr[6] = {1, 2, 3, 4, 5, 8};

    cout << "Sum is: " << getSum(arr + 3, 3) << endl;
}
