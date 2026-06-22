// -----------------------------------------------------------------------------
// Learning focus: Linear Search Using Recursion
// Purpose: Implements Linear Search Using Recursion by checking elements one at a time.
// Core idea: Stop when the target is found; otherwise continue until the searchable range is exhausted.
// Complexity note: Worst-case time is O(n); iterative extra space is O(1), while recursion uses O(n) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    if (*arr == key)
    {
        return true;
    }
    return linearSearch(arr + 1, size - 1, key);
}
int main()
{
    int nums[5] = {1, 2, 30, 4, 5};
    cout << linearSearch(nums, 5, 30) << endl;
}