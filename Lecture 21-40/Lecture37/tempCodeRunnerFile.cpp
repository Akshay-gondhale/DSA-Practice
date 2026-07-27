//* LeetCode Problem: https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Generates all possible subsets of the given array using recursion.
 *
 * This function follows the classic backtracking (pick / not-pick) approach.
 * For every element, two recursive choices are explored:
 * - Exclude the current element from the subset.
 * - Include the current element in the subset.
 *
 * Once all elements have been processed, the currently constructed subset is
 * added to the final answer.
 *
 * @param numArr Input array whose subsets are to be generated.
 * @param index Current index being processed.
 * @param prevOutput Subset constructed so far.
 * @param ans Stores all generated subsets.
 *
 * @note Both `numArr` and `prevOutput` are intentionally passed by value so
 * each recursive branch works on its own independent copy.
 *
 * Time Complexity: O(2^n * n)
 * Space Complexity: O(n) (excluding the output storage)
 */
void createSubSet(vector<int> numArr, int index, vector<int> prevOutput, vector<vector<int>> &ans)
{
    //* Base case: All elements have been considered, so store the current subset.
    if (index >= numArr.size())
    {
        ans.push_back(prevOutput);
        return;
    }

    //? Choice 1: Exclude the current element and move to the next index.
    createSubSet(numArr, index + 1, prevOutput, ans);

    //? Choice 2: Include the current element before exploring the next index.
    prevOutput.push_back(numArr[index]);
    createSubSet(numArr, index + 1, prevOutput, ans);
}

/**
 * @brief Demonstrates recursive subset generation.
 *
 * Initializes a sample array, generates all possible subsets,
 * and prints each subset on a separate line.
 *
 * Time Complexity: O(2^n * n)
 * Space Complexity: O(2^n * n) (including the stored subsets)
 */
int main()
{
    //* Sample input array.
    vector<int> numArr = {1, 2, 3};

    int index = 0;

    //* Represents the subset currently being constructed.
    vector<int> output;

    //* Stores every generated subset.
    vector<vector<int>> ans;

    //* Generate all subsets.
    createSubSet(numArr, index, output, ans);

    //* Print every generated subset.
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
}