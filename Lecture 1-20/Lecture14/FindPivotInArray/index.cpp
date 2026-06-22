// -----------------------------------------------------------------------------
// Learning focus: Find Pivot In Array
// Finds the smallest element in a rotated sorted array; its index is the
// rotation pivot. Time complexity: O(log n) | Extra space: O(1)
// -----------------------------------------------------------------------------
#include <iostream>
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
    int start = 0;
    int end = size - 1;
    // Values greater than or equal to numArr[0] lie in the left sorted part;
    // smaller values lie in the right part containing the rotation pivot.
    while (start < end)
    {
        // Choose the middle index with an overflow-safe formula before deciding which half remains relevant.
        int mid = start + (end - start) / 2;

        cout << start << "--" << mid << "--" << end << endl;
        if (numArr[mid] > numArr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    cout << start << endl;
}
