#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Partitions the array around the first element as the pivot.
 *
 * This implementation selects the first element as the pivot, counts how many
 * elements are less than or equal to it to determine its final sorted position,
 * and then rearranges the remaining elements so that:
 * - all elements on the left of the pivot are less than or equal to it.
 * - all elements on the right of the pivot are greater than it.
 *
 * @param numArr Pointer to the array being partitioned.
 * @param start Starting index of the current subarray.
 * @param end Ending index of the current subarray.
 * @return The final index of the pivot element after partitioning.
 *
 * @note This partitioning strategy performs two passes:
 *       one to determine the pivot's final position and another to place
 *       misplaced elements on their correct side.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int partition(int *numArr, int start, int end)
{
    int numsLessThanStartElement = 0;
    int pivotNum = numArr[start];

    //* Count elements that belong on the left side of the pivot.
    for (int i = start + 1; i <= end; i++)
    {
        if (numArr[i] <= pivotNum)
        {
            numsLessThanStartElement++;
        }
    }

    //* Compute the pivot's final sorted position.
    int pivotIndex = start + numsLessThanStartElement;

    //* Move the pivot to its correct position before rearranging other elements.
    swap(numArr[start], numArr[pivotIndex]);

    int left = start, right = end;

    //* Ensure elements on each side satisfy the partition invariant.
    while (left < pivotIndex && right > pivotIndex)
    {
        if (numArr[left] < pivotNum)
        {
            left++;
        }

        if (numArr[right] > pivotNum)
        {
            right--;
        }

        //? Both pointers have found misplaced elements, so swap them.
        if (numArr[left] > pivotNum && numArr[right] < pivotNum)
        {
            swap(numArr[left], numArr[right]);
            left++;
            right--;
        }
    }

    return pivotIndex;
}

/**
 * @brief Sorts an array using the Quick Sort algorithm.
 *
 * Quick Sort recursively partitions the array around a pivot and sorts the
 * resulting left and right subarrays independently until each subarray
 * contains at most one element.
 *
 * @param numArr Pointer to the array to be sorted.
 * @param start Starting index of the current subarray.
 * @param end Ending index of the current subarray.
 *
 * Time Complexity:
 * - Best/Average: O(n log n)
 * - Worst: O(n²)
 *
 * Space Complexity:
 * - Average: O(log n) (recursion stack)
 * - Worst: O(n)
 */
void quickSort(int *numArr, int start, int end)
{
    //! A subarray with zero or one element is already sorted.
    if (start >= end)
    {
        return;
    }

    //* Partition the current range and obtain the pivot's final position.
    int pivotIndex = partition(numArr, start, end);

    //* Recursively sort elements smaller than the pivot.
    quickSort(numArr, start, pivotIndex - 1);

    //* Recursively sort elements greater than the pivot.
    quickSort(numArr, pivotIndex + 1, end);
}

/**
 * @brief Demonstrates Quick Sort on a sample array.
 *
 * Time Complexity: O(n log n) average
 * Space Complexity: O(log n) average
 */
int main()
{
    int numArr[6] = {3, 7, 1, 2, 8, 4};
    int size = 6;

    cout << "ok" << endl;

    quickSort(numArr, 0, size - 1);

    cout << "ok2" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << numArr[i] << " ";
    }

    cout << endl;
}