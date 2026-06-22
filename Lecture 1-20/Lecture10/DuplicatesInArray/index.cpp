// -----------------------------------------------------------------------------
// Learning focus: Duplicates In Array
// Purpose: Solves Duplicates In Array by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// Problem link:
// https://www.naukri.com/code360/problems/duplicate-in-array_893397
//
// Given an array of size n containing numbers from 1 to n - 1, find the
// duplicate number. Exactly one number is assumed to appear more than once.
#include <iostream>
using namespace std;

// Finds the duplicate using the XOR (^) operator.
//
// Important XOR properties:
// 1. x ^ x = 0       -> equal values cancel each other.
// 2. x ^ 0 = x       -> XOR with zero leaves a value unchanged.
// 3. XOR is associative and commutative, so the order does not matter.
//
// The array contains every number from 1 to size - 1, plus one duplicate.
// XORing all array elements and then XORing the expected values 1 to size - 1
// cancels every non-duplicate value. The duplicate is the only value left.
//
// Time complexity: O(n), because the array is traversed twice.
// Space complexity: O(1), because no extra array or collection is used.
int findDuplicate(int arr[], int size)
{
    // Store the cumulative XOR. Starting with 0 does not affect the result.
    int ans = 0;

    // XOR all values present in the array, including the duplicate.
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR all values that should occur once: 1, 2, ..., size - 1.
    // Each expected value cancels its matching value from the first loop.
    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
    }

    // After cancellation, only the duplicated number remains.
    return ans;
}

int main()
{
    // Read the total number of elements in the array.
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    // Create an array containing 'size' integers.
    int numArr[size];

    // Read each array element from the user.
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }

    // Compute and display the duplicate number.
    int duplicatedNum = findDuplicate(numArr, size);
    cout << "Duplicated number in array is: " << duplicatedNum << endl;
}
