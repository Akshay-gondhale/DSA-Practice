// -----------------------------------------------------------------------------
// Learning focus: Search In Sorted Rotated Array
// Purpose: Demonstrates Search In Sorted Rotated Array and shows the data flow through a complete example.
// Core idea: Follow the helper functions first, then main(), which prepares input and displays the result.
// Complexity note: Complexity depends on the loops and helper functions identified below.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2
#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int findPivot(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}
int searchInRotatedSortedArr(int arr[], int size, int pivot, int key)
{
    int start = 0;
    int end = size - 1;
    if (arr[pivot] <= key && key <= arr[end])
    {
        start = pivot;
    }
    else
    {
        end = pivot;
    }
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else
        {
            if (arr[mid] < key)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
    }
    if (arr[start] == key)
    {

        return start;
    }
    else
    {
        return -1;
    }
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
    int keyToSearch;
    cout << "Enter key to search: ";
    cin >> keyToSearch;
    int pivotIndex = findPivot(numArr, size);
    int keyIndex = searchInRotatedSortedArr(numArr, size, pivotIndex, keyToSearch);
    cout << keyToSearch << " is present on index: " << keyIndex << endl;
}