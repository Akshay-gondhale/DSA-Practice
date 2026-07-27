#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Generates all possible subsets (power set) of the given array using Bit Manipulation.
 *
 * Each integer from 0 to (2^n - 1) acts as a bitmask, where every bit represents
 * whether the corresponding element in the input array should be included in the
 * current subset.
 *
 * Example for n = 3:
 * Bitmask 000 -> {}
 * Bitmask 001 -> {1}
 * Bitmask 010 -> {2}
 * Bitmask 011 -> {1,2}
 * ...
 * Bitmask 111 -> {1,2,3}
 *
 * @param nums Input array whose power set is to be generated.
 * @return A vector containing all possible subsets.
 *
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n * 2^n)
 */
vector<vector<int>> createSubset(vector<int> &nums)
{

    int arrSize = nums.size();

    //* Total possible subsets for an array of size n is always 2^n.
    //? Left shifting 1 by n positions computes 2^n efficiently.
    //! Example:
    //? n = 3
    //? 1      -> 001
    //? 1 << 3 -> 1000 (decimal 8)
    int totalSubsets = 1 << arrSize;

    vector<vector<int>> ans;

    //* Iterate through every possible bitmask from 0 to (2^n - 1).
    //? Each bitmask uniquely represents one subset.
    //! Example for n = 3:
    //? 0 -> 000
    //? 1 -> 001
    //? 2 -> 010
    //? 3 -> 011
    //? ...
    //? 7 -> 111
    for (int i = 0; i < totalSubsets; i++)
    {
        vector<int> subset;

        //* Check every bit of the current bitmask.
        //? Bit position j corresponds to nums[j].
        for (int j = 0; j < arrSize; j++)
        {
            //* Create a mask with only the j-th bit set.
            //! Example:
            //? j = 0 -> 001
            //? j = 1 -> 010
            //? j = 2 -> 100

            //* If the j-th bit is set in the current bitmask,
            //? include nums[j] in the current subset.
            if (i & (1 << j))
            {
                subset.push_back(nums[j]);
            }
        }

        //* Store the subset represented by the current bitmask.
        ans.push_back(subset);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = createSubset(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}