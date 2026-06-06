#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
        return false;
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