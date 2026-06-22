// -----------------------------------------------------------------------------
// Learning focus: Simple Binary Search
// Purpose: Solves Simple Binary Search by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        // OPTIMIZATION
        // there can be a scenrario where start + end might exceed the int range of 2^31
        // so to handle this scenario we are going to change our formula from
        // mid = (start + end)/2
        // to =>
        // mid = start + (end - start) / 2

        int mid = start + (end - start) / 2;
        // cout << start << "--" << mid << "--" << end << endl;
        if (arr[mid] == key)
        {
            return mid;
        }
        else
        {
            if (arr[mid] < key)
            {
                // if mid is smaller than key then moving start to mid + 1
                start = mid + 1;
            }
            else if (arr[mid] > key)
            {
                // if mid is greater than key then bringing end towards mid -1;
                end = mid - 1;
            }
        }
    }
    // returning -1 if element not found
    return -1;
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int numArr[size];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    int keyToSearch;
    cout << "Enter key to search in array: ";
    cin >> keyToSearch;
    int foundKeyIndex = binarySearch(numArr, size, keyToSearch);
    if (foundKeyIndex != -1)
    {
        cout << "Element is present on " << foundKeyIndex << " index" << endl;
    }
    else
    {
        cout << "Element not present in array." << endl;
    }
    return 0;
}
