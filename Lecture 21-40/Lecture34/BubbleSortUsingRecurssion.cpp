// -----------------------------------------------------------------------------
// Learning focus: Bubble Sort Using Recursion
// Purpose: Sorts an array with recursive bubble sort.
// Core idea: One pass moves the largest remaining value to the end, then recursion sorts the shorter prefix.
// Complexity note: Time is O(n^2), with O(n) recursive stack space.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
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
// Sorts by repeatedly swapping adjacent out-of-order values; the recursive form then sorts a shorter prefix.
void bubbleSort(int arr[], int size)
{
    // Key idea: After one complete pass, the largest unsorted value is fixed at the end.
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
