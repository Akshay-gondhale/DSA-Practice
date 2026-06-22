// -----------------------------------------------------------------------------
// Learning focus: Binary Search Recursion
// Purpose: Solves Binary Search Recursion by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Searches a sorted range by comparing its middle value with the target.
bool binarySearch(int arr[], int start, int end, int key)
{
    // Key idea: Discard the half that cannot contain the key; this halves the remaining search space each step.
    if (start > end)
        return false;
    // Choose the middle index with an overflow-safe formula before deciding which half remains relevant.
    int mid = (end - start) / 2 + start;
    if (mid == key)
        return true;
    if (mid > key)
    {
        return binarySearch(arr, start, mid - 1, key);
    }
    else
    {

        return binarySearch(arr, mid + 1, end, key);
    }
}
int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    cout << binarySearch(nums, 0, 5, 2) << endl;
}
