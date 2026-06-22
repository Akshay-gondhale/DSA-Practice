// -----------------------------------------------------------------------------
// Learning focus: Stack And Heap Memory
// Purpose: Demonstrates Stack And Heap Memory and explicit dynamic-memory management.
// Core idea: Allocate required rows/elements on the heap, access them through pointers, and release every allocation with matching delete operations.
// Complexity note: Memory usage is proportional to the number of dynamically allocated elements.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
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
    // Key idea: Track whether each expression represents a value, an address, or an alias; dereferencing moves one level toward the stored value.
    for (int i = 0; i < 5; i++)
    {
        numArr[i] = (i + 1) * 10;
    }
    printingDynamicArray(numArr, 5);
    delete[] numArr; // clean up
}
