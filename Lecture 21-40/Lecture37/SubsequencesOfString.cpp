//! Code360 Problem:
//! https://www.naukri.com/code360/problems/subsequences-of-string_985087?leftPanelTab=0&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Generates all non-empty subsequences of a string using recursion.
 *
 * This function uses the classic include/exclude recursion technique.
 * For each character, two recursive choices are explored:
 * - Exclude the current character from the subsequence.
 * - Include the current character in the subsequence.
 *
 * Whenever all characters have been processed, the constructed subsequence
 * is added to the answer if it is non-empty.
 *
 * @param inputStr Input string whose subsequences are to be generated.
 * @param index Current character index being processed.
 * @param output Subsequence constructed so far.
 * @param ans Stores all generated non-empty subsequences.
 *
 * @note Both `inputStr` and `output` are intentionally passed by value so
 * each recursive branch operates on its own independent copy.
 *
 * Time Complexity: O(2^n * n)
 * Space Complexity: O(n) (excluding the output storage)
 */
void createSubSequences(string inputStr, int index, string output, vector<string> &ans)
{
    //* Base case: All characters have been processed.
    if (index >= inputStr.length())
    {
        //? Ignore the empty subsequence as required by the problem.
        if (output.length() > 0)
            ans.push_back(output);

        return;
    }

    //? Choice 1: Exclude the current character.
    createSubSequences(inputStr, index + 1, output, ans);

    //? Choice 2: Include the current character before processing the next one.
    output += inputStr[index];
    index++;
    createSubSequences(inputStr, index, output, ans);
}

/**
 * @brief Demonstrates recursive generation of all non-empty subsequences.
 *
 * Initializes a sample string, generates every possible non-empty
 * subsequence, and prints them.
 *
 * Time Complexity: O(2^n * n)
 * Space Complexity: O(2^n * n) (including the stored subsequences)
 */
int main()
{
    //* Sample input string.
    string inputStr = "abc";

    int index = 0;

    //* Represents the subsequence currently being constructed.
    string output = "";

    //* Stores all generated non-empty subsequences.
    vector<string> ans;

    //* Generate all subsequences.
    createSubSequences(inputStr, index, output, ans);

    //* Print every generated subsequence.
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}