// -----------------------------------------------------------------------------
// Learning focus: Peak In An Moutain Array
// Purpose: Solves Peak In An Moutain Array by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
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

int findPeak(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
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