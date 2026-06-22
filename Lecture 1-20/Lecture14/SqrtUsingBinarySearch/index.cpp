// -----------------------------------------------------------------------------
// Learning focus: Sqrt Using Binary Search
// Purpose: Solves Sqrt Using Binary Search by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/sqrtx/description/
#include <iostream>
using namespace std;
// Finds the integer square root with binary search over possible answers.
int findSqrt(int x)
{
    // Key idea: Compare mid*mid with the number and retain the greatest candidate whose square does not exceed it.
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }
    int start = 0;
    int end = x;
    long long int ans = -1;
    while (start < end)
    {
        long long int mid = start + (end - start) / 2;
        long long int square = mid * mid;
        if (square == x)
        {
            return mid;
        }
        else
        {
            if (square < x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
    }
    return ans;
}
int main()
{
    int num;
    cout << "Enter a number to find sqrt of it: ";
    cin >> num;
    int sqrt = findSqrt(num);
    cout << "Square root of " << num << " is: " << sqrt << endl;
}
