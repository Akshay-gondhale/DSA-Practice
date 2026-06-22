// -----------------------------------------------------------------------------
// Learning focus: Find Pivot In Array
// Purpose: Solves Find Pivot In Array by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int numArr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;

        cout << start << "--" << mid << "--" << end << endl;
        if (numArr[mid] > numArr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    cout << start << endl;
}