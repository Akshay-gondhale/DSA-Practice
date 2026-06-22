// -----------------------------------------------------------------------------
// Learning focus: Rotate Array
// Purpose: Handles Rotate Array using modular positions or order-break counting.
// Core idea: Rotation wraps indices around the array; sorted-rotation validation counts where ascending order breaks.
// Complexity note: Time is O(n); extra space depends on whether a temporary result array is used.
// -----------------------------------------------------------------------------
// https : // leetcode.com/problems/rotate-array/submissions/1863284025/
#include <iostream>
#include <vector>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArr(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
// Moves elements to their rotated positions while preserving every original value.
void rotateArray(vector<int> nums, int k)
{
    vector<int> rotatedArr(nums.size());
    // Key idea: Modular indexing wraps positions that move beyond the last valid index back to the beginning.
    for (int i = 0; i < nums.size(); i++)
    {
        // EXPLAINATION FOR THIS LINE:
        // mod of n always gives a number between 0 to n-1
        // for case 1 (normal case):
        // [0, 1, 2, 3]
        // new position for index 1 with k = 2 will be:
        // (1 + 2) % 4 = 3 % 4 = 3
        // case 2 (last elems of array):
        // new position of 3rd index will be:
        // (3 + 2) % 4 = 5 % 4 = 1
        int newIndex = (i + k) % nums.size();
        rotatedArr[newIndex] = nums[i];
    }
    nums = rotatedArr;
    printArr(rotatedArr);
}
int main()
{
    vector<int> nums;
    int size;

    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    cout << endl;
    rotateArray(nums, 2);
}
