#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int size)
{
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