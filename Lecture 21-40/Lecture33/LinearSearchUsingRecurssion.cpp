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