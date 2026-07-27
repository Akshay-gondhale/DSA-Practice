//? LeetCode Problem: https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Generates all permutations of the given array using backtracking.
 *
 * This function fixes one position at a time by swapping the current element
 * with every possible candidate. After exploring a choice recursively, it
 * restores the original arrangement (backtracking) so that the next choice
 * starts from the same state.
 *
 * Approach:
 * - Fix one element at the current index.
 * - Recursively generate permutations for the remaining positions.
 * - Backtrack by undoing the swap before trying the next candidate.
 *
 * @param nums Reference to the input array whose elements are being permuted.
 * @param index Current position being fixed in the permutation.
 * @param ans Stores all generated permutations.
 * @return None.
 *
 * @note The input array is modified temporarily during recursion but restored
 * after each recursive call.
 *
 * Time Complexity: O(N × N!)
 * Space Complexity: O(N) (Recursion stack, excluding the output container)
 */
void findPermutations(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    //* Once every position has been fixed, a complete permutation is formed.
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    //* Try every remaining element as the candidate for the current position.
    for (int i = index; i < nums.size(); i++)
    {
        //? Place the selected element at the current fixed position.
        swap(nums[index], nums[i]);

        //? Generate permutations for the remaining unfixed positions.
        findPermutations(nums, index + 1, ans);

        //? Restore the original arrangement before exploring the next choice.
        swap(nums[index], nums[i]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;

    findPermutations(nums, 0, ans);

    int count = 0;

    //* Print all generated permutations.
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
            count++;
        }
        cout << endl;
    }
}