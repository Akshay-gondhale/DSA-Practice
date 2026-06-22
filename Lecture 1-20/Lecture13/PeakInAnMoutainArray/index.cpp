// -----------------------------------------------------------------------------
// Learning focus: Peak In An Moutain Array
// Purpose: Solves Peak In An Moutain Array by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#include <iostream>
using namespace std;

// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Finds the mountain-array peak using the direction of the slope around the middle index.
int findPeak(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    // Key idea: An increasing slope means the peak is to the right; a decreasing slope keeps mid as a candidate.
    while (start < end)
    {
        // Choose the middle index with an overflow-safe formula before deciding which half remains relevant.
        int mid = start + ((end - start) / 2);
        int midLeft = mid - 1;
        int midRight = mid + 1;
        cout << midLeft << "--" << mid << "--" << midRight << endl;
        cout << arr[midLeft] << "--" << arr[mid] << "--" << arr[midRight] << endl;
        if (arr[midLeft] < arr[mid] && arr[mid] > arr[midRight])
        {
            return mid;
        }
        else
        {
            if (arr[midRight] > arr[mid])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
    }
    return -1;
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
    int peak = findPeak(numArr, size);
    cout << peak;
}
