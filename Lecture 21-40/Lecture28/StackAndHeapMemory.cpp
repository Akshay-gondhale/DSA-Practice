// -----------------------------------------------------------------------------
// Learning focus: Stack And Heap Memory
// Purpose: Demonstrates Stack And Heap Memory and explicit dynamic-memory management.
// Core idea: Allocate required rows/elements on the heap, access them through pointers, and release every allocation with matching delete operations.
// Complexity note: Memory usage is proportional to the number of dynamically allocated elements.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void printingDynamicArray(int *numArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int *numInHeap = new int;
    cout << "Address in numInHeap: " << numInHeap << endl;
    *numInHeap = 5;
    cout << "value of numInHeap: " << *numInHeap << endl;
    delete numInHeap; // clean up
    // array in dynamic memory
    int *numArr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        numArr[i] = (i + 1) * 10;
    }
    printingDynamicArray(numArr, 5);
    delete[] numArr; // clean up
}