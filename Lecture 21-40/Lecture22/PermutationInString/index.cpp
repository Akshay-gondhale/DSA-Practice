// -----------------------------------------------------------------------------
// Learning focus: Permutation In String
// Purpose: Checks whether a string contains a permutation of another string.
// Core idea: Maintain character-frequency counts for a fixed-size sliding window and compare them with the target counts.
// Complexity note: Time is O(n + alphabet size), with O(alphabet size) extra space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/permutation-in-string/description/
#include <iostream>
using namespace std;
void printArr(int charArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << charArr[i] << " ";
    }
    cout << endl;
}
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

    // comparing with s2
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