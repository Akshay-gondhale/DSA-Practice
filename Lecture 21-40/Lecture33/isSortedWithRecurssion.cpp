// -----------------------------------------------------------------------------
// Learning focus: is Sorted With Recursion
// Purpose: Demonstrates is Sorted With Recursion through recursion.
// Core idea: A base case handles the smallest input; each recursive call reduces the problem and the returning calls combine or print results.
// Complexity note: Recursion depth and time follow the amount by which each call reduces the input.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Checks recursively that every adjacent pair is in nondecreasing order.
bool isSorted(int arr[], int size)
{
    // Key idea: One inverted adjacent pair disproves sorted order; otherwise recurse on the shorter suffix.
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (*arr > *(arr + 1))
    {
        return false;
    }
    return isSorted(arr + 1, size - 1);
}
int main()
{
    int nums[5] = {2, 4, 15, 6, 7};
    bool result = isSorted(nums, 5);
    cout << result << endl;
}
