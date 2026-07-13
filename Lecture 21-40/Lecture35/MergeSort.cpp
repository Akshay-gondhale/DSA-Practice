#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Merges two consecutive sorted subarrays into a single sorted range.
 *
 * The function assumes that the subarray `numArr[start...mid]` and
 * `numArr[mid+1...end]` are already sorted. It creates temporary left and
 * right arrays, copies the respective elements, and merges them back into
 * the original array while maintaining sorted order.
 *
 * @param numArr Pointer to the array being sorted.
 * @param start Starting index of the current range.
 * @param end Ending index of the current range.
 *
 * @note Both halves must already be sorted before calling this function.
 *
 * Time Complexity: O(n), where n = end - start + 1
 * Space Complexity: O(n)
 */
void mergeArraysInOrder(int *numArr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int lenOfLeftArray = mid - start + 1;
    int lenOfRightArray = end - mid;

    int *leftArray = new int[lenOfLeftArray];
    int *rightArray = new int[lenOfRightArray];

    //* Copy the left half into a temporary array.
    int mainIndexArray = start;
    for (int i = 0; i < lenOfLeftArray; i++)
    {
        leftArray[i] = numArr[mainIndexArray++];
    }

    //* Copy the right half into a temporary array.
    mainIndexArray = mid + 1;
    for (int i = 0; i < lenOfRightArray; i++)
    {
        rightArray[i] = numArr[mainIndexArray++];
    }

    //* Merge both sorted temporary arrays back into the original array.
    mainIndexArray = start;
    int leftArrayIndex = 0;
    int rightArrayIndex = 0;
    while (leftArrayIndex < lenOfLeftArray && rightArrayIndex < lenOfRightArray)
    {
        //? Always place the smaller element first to preserve sorted order.
        if (leftArray[leftArrayIndex] < rightArray[rightArrayIndex])
        {
            numArr[mainIndexArray++] = leftArray[leftArrayIndex++];
        }
        else
        {
            numArr[mainIndexArray++] = rightArray[rightArrayIndex++];
        }
    }

    //* Copy any remaining elements from the left half.
    while (leftArrayIndex < lenOfLeftArray)
    {
        numArr[mainIndexArray++] = leftArray[leftArrayIndex++];
    }

    //* Copy any remaining elements from the right half.
    while (rightArrayIndex < lenOfRightArray)
    {
        numArr[mainIndexArray++] = rightArray[rightArrayIndex++];
    }

    //* Release dynamically allocated temporary arrays.
    delete[] leftArray;
    delete[] rightArray;
}

/**
 * @brief Sorts an array using the Merge Sort algorithm.
 *
 * Merge Sort follows the divide-and-conquer paradigm. It recursively divides
 * the array into two halves until each subarray contains a single element,
 * then merges the sorted halves to produce the final sorted array.
 *
 * @param numArr Pointer to the array to be sorted.
 * @param start Starting index of the current range.
 * @param end Ending index of the current range.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
void mergeSort(int *numArr, int start, int end)
{
    //! A subarray with zero or one element is already sorted.
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    //* Recursively sort the left half.
    mergeSort(numArr, start, mid);

    //* Recursively sort the right half.
    mergeSort(numArr, mid + 1, end);

    //* Merge the two sorted halves.
    mergeArraysInOrder(numArr, start, end);
}

int main()
{
    int numArr[5] = {4, 3, 5, 2, 8};
    int size = 5;

    mergeSort(numArr, 0, size - 1);

    cout << "After merging two arrays in order: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}