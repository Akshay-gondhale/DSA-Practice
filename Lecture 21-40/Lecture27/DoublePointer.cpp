// -----------------------------------------------------------------------------
// Learning focus: Double Pointer
// Purpose: Explores Double Pointer and how C++ accesses objects through addresses or aliases.
// Core idea: Track both the stored address and the value reached by dereferencing; note when a function receives a copy versus an address/reference.
// Complexity note: These examples emphasize memory semantics rather than algorithmic complexity.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // another hack of remembering pointer is as follows:
    // int temp = 5;
    // if we want to create pointer of above line we simply copy its datatype and add * to it
    // e.g: int* ptr = &temp;
    // thats why double pointer also works same if you want to create pointer of pointer copy its data type
    // and add one more * as follows:
    // e.g: int** ptr2 = &ptr;
    // this line stores address of old pointer in ptr2.
    int temp = 5;
    cout << "Value of temp: " << temp << endl;
    cout << "Address of temp: " << &temp << endl;
    cout << endl;
    // creating a pointer;
    int *ptr1 = &temp;
    cout << "Address stored inside ptr1: " << ptr1 << endl;
    cout << "Address of ptr1: " << &ptr1 << endl;
    cout << endl;
    // creating a second pointer using two *
    int **ptr2 = &ptr1;
    cout << "Address stored inside ptr2: " << ptr2 << endl;
    cout << "Address of ptr2: " << &ptr2 << endl;
    cout << endl;
    // similarly you can create more pointers with using more *
}