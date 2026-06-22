// -----------------------------------------------------------------------------
// Learning focus: Lecture16
// Purpose: Demonstrates Lecture16 and shows the data flow through a complete example.
// Core idea: Follow the helper functions first, then main(), which prepares input and displays the result.
// Complexity note: Complexity depends on the loops and helper functions identified below.
// -----------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArr(int numArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
// Sorts by selecting the smallest remaining value and placing it at the current front position.
void selectionSort(int numArr[], int size)
{
    cout << endl;
    cout << "Given array: ";
    printArr(numArr, size);
    // Key idea: The prefix before the outer-loop index is already in final sorted order.
    for (int i = 0; i < size; i++)
    {
        int smallNumIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (numArr[j] < numArr[smallNumIndex])
            {
                smallNumIndex = j;
            }
        }
        swap(numArr[i], numArr[smallNumIndex]);
    }
    cout << "Sorted array: ";
    printArr(numArr, size);
}
int main()
{
    int size;
    cout << "Enter array length: ";
    cin >> size;
    int numArr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    selectionSort(numArr, size);
}
