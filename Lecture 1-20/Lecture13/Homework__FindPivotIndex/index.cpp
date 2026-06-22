// -----------------------------------------------------------------------------
// Learning focus: Homework: Find Pivot Index
// Purpose: Solves Homework: Find Pivot Index by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/find-pivot-index/description/
#include <iostream>
#include <vector>
using namespace std;
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
