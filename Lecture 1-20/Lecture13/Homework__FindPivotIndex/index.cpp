// -----------------------------------------------------------------------------
// Learning focus: Homework: Find Pivot Index
// Finds an index whose left-side sum equals its right-side sum.
// Time complexity: O(n) | Extra space: O(1)
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/find-pivot-index/description/
#include <iostream>
#include <vector>
using namespace std;
// Returns the sum of the supplied elements.
int sumOfArr(int arr[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }
    return sum;
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

    // Keep the right and left sums incrementally instead of recomputing both
    // sides for every candidate index.
    int rightSum = sumOfArr(numArr, 0, size - 1);
    int leftSum = 0;
    for (int i = 0; i < size; i++)
    {
        int rightRemaining = rightSum - numArr[i];
        if (rightRemaining == leftSum)
        {
            cout << i << endl;
        }
        rightSum = rightRemaining;
        leftSum += numArr[i];
    }
}
