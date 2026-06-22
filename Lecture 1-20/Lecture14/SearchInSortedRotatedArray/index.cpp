// -----------------------------------------------------------------------------
// Learning focus: Search In Sorted Rotated Array
// Purpose: Finds a target in an ascending array that has been rotated once.
// Core idea: First locate the smallest element (the rotation pivot). Then choose
// the sorted half that can contain the key and run binary search only there.
// Complexity: Both searches take O(log n) time and O(1) extra space.
// Assumption: The input is non-empty, sorted before rotation, and has distinct
// values. Those conditions make comparisons with arr[0] unambiguous.
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2
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
// Locates the rotation pivot that separates the two sorted portions of the array.
int findPivot(int arr[], int size)
{
    // The pivot is the index of the smallest element. It separates the two
    // individually sorted portions of the rotated array.
    int start = 0;
    int end = size - 1;

    // Keep reducing the candidate interval until both boundaries meet at the
    // smallest element. Using start < end allows mid itself to remain a candidate.
    while (start < end)
    {
        // This form avoids the possible overflow of (start + end) / 2.
        int mid = start + (end - start) / 2;

        // Values at least as large as arr[0] belong to the left sorted portion.
        // Therefore, the rotation point must be strictly to the right of mid.
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            // mid is in the right sorted portion and may itself be the smallest
            // value, so keep mid in the candidate interval.
            end = mid;
        }
    }

    // start == end, and this common index is the rotation pivot.
    return start;
}

// Chooses the sorted half whose value range contains the key, then applies binary search there.
int searchInRotatedSortedArr(int arr[], int size, int pivot, int key)
{
    int start = 0;
    int end = size - 1;

    // The pivot-to-end portion is sorted. Restrict the search to it when the
    // key lies within its inclusive value range.
    if (arr[pivot] <= key && key <= arr[end])
    {
        start = pivot;
    }
    else
    {
        // Otherwise search the sorted portion before the pivot. Keeping pivot
        // as the upper bound is harmless because it is checked by the search.
        end = pivot;
    }

    // Perform binary search inside the selected sorted interval.
    while (start < end)
    {
        // Choose the middle index with an overflow-safe formula before deciding which half remains relevant.
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else
        {
            if (arr[mid] < key)
            {
                // The key can only be to the right of mid.
                start = mid + 1;
            }
            else
            {
                // The key is smaller; preserve mid as a possible final candidate.
                end = mid;
            }
        }
    }
    // The loop stops with one candidate index, which still needs to be checked.
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

    // Split the task into two logarithmic searches: locate the rotation point,
    // then search the only sorted portion whose values can contain the key.
    int pivotIndex = findPivot(numArr, size);
    int keyIndex = searchInRotatedSortedArr(numArr, size, pivotIndex, keyToSearch);
    cout << keyToSearch << " is present on index: " << keyIndex << endl;
}
