// -----------------------------------------------------------------------------
// Learning focus: Bubble Sort Using Recursion
// Purpose: Sorts an array with recursive bubble sort.
// Core idea: One pass moves the largest remaining value to the end, then recursion sorts the shorter prefix.
// Complexity note: Time is O(n^2), with O(n) recursive stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, size - 1);
}
int main()
{
    int nums[] = {2, 6, 3, 8, 1};
    bubbleSort(nums, 5);
    printArr(nums, 5);
}