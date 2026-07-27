// [https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Generates all possible letter combinations for a phone number using Backtracking.
 *
 * The algorithm recursively explores every possible character corresponding to
 * each digit. At every recursion level, one character is chosen for the current
 * digit, and the search continues for the remaining digits until a complete
 * combination is formed.
 *
 * @param digits Input string containing digits from '2' to '9'.
 * @param index Current position being processed in the input string.
 * @param output Stores the partially constructed letter combination.
 * @param ans Stores all valid letter combinations.
 * @param mapping Maps each digit to its corresponding characters on a phone keypad.
 *
 * @note Digits '0' and '1' intentionally map to empty strings since they do not
 *       have associated letters on a traditional phone keypad.
 *
 * Time Complexity: O(4^n)
 * Space Complexity: O(n) (excluding the output vector)
 */
void findLettersCombination(string digits, int index, string output, vector<string> &ans, string mapping[])
{
    //* Base case: A complete combination has been formed.
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    //* Convert the current digit character into its corresponding integer.
    //? Characters store ASCII values, so subtracting '0' converts
    //? '2' -> 2, '5' -> 5, etc.
    int currentDigit = digits[index] - '0';

    //* Retrieve all possible letters mapped to the current digit.
    string digitLetterMapping = mapping[currentDigit];

    //* Try every possible letter for the current digit.
    for (int i = 0; i < digitLetterMapping.length(); i++)
    {
        //* Choose the current character.
        output.push_back(digitLetterMapping[i]);

        //* Recursively build combinations for the remaining digits.
        findLettersCombination(digits, index + 1, output, ans, mapping);

        //* Backtrack by removing the previously chosen character,
        //? allowing the next possible letter to be explored.
        output.pop_back();
    }
}

int main()
{
    string inputString = "23";

    //* Phone keypad mapping where index represents the digit.
    //! Digits 0 and 1 do not have any corresponding letters.
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string output = "";

    //* Handle the edge case of an empty input string.
    if (inputString.length() == 0)
        return 0;

    vector<string> ans;

    findLettersCombination(inputString, 0, output, ans, mapping);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}