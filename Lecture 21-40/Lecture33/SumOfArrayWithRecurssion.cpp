// -----------------------------------------------------------------------------
// Learning focus: Sum Of Array With Recursion
// Purpose: Demonstrates Sum Of Array With Recursion through recursion.
// Core idea: A base case handles the smallest input; each recursive call reduces the problem and the returning calls combine or print results.
// Complexity note: Recursion depth and time follow the amount by which each call reduces the input.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int sumOfArr(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return *arr;
    }
    return *arr + sumOfArr(arr + 1, size - 1);
}
int main()
{
    int nums[5] = {1, 2, 3, 4, 5};
    cout << sumOfArr(nums, 5) << endl;
}