// -----------------------------------------------------------------------------
// Learning focus: Permutation In String
// Purpose: Checks whether a string contains a permutation of another string.
// Core idea: Build a 26-letter frequency table for every candidate window and
// compare it with the first string's frequency table.
// Complexity: O((|s2| - |s1| + 1) * |s1|) time and O(1) alphabet space.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/permutation-in-string/description/
#include <iostream>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArr(int charArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << charArr[i] << " ";
    }
    cout << endl;
}
// Compares fixed-alphabet frequency tables to determine whether two windows are permutations.
bool checkEqual(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
// Checks every fixed-size window by rebuilding its frequency table.
bool checkPermutationInSting(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return false;
    }
    int allChars[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int increamentIndex = s1[i] - 'a';
        allChars[increamentIndex]++;
    }

    // Each window has the same length as s1; equal frequency tables mean the
    // window is a permutation even when its character order differs.
    for (int i = 0; i < s2.length() - s1.length() + 1; i++)
    {
        int allChars2[26] = {0};
        for (int j = i; j < i + s1.length(); j++)
        {
            int increamentIndex = s2[j] - 'a';
            allChars2[increamentIndex]++;
        }
        if (checkEqual(allChars, allChars2, 26))
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string s1, s2;
    cout << "Enter string s1: " << endl;
    getline(cin, s1);
    cout << "Enter string s2: " << endl;
    getline(cin, s2);
    bool output = checkPermutationInSting(s1, s2);
    cout << output << endl;
}
