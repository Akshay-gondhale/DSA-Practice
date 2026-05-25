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