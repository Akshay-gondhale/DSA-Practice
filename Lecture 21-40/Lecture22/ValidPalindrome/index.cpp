// -----------------------------------------------------------------------------
// Learning focus: Valid Palindromee
// Purpose: Checks Valid Palindromee by comparing characters from opposite ends.
// Core idea: Advance inward while corresponding normalized characters match; any mismatch disproves the palindrome.
// Complexity note: Time is O(n); iterative code uses O(1) extra space and recursion uses O(n) stack space.
// -----------------------------------------------------------------------------
// https : // leetcode.com/problems/valid-palindrome/description/
#include <iostream>
#include <string>
using namespace std;
// Classifies whether a character is alphanumeric so punctuation and spaces can be ignored.
bool isValidChar(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Normalizes uppercase letters to lowercase so palindrome comparison is case-insensitive.
char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {

        // eg: "C" ASCII is 67
        // "A" ASCII is 65
        // "a" ASCII is 97
        // 67 - 65 + 97 => 99
        // 99 is ASCII of 'c
        return c - 'A' + 'a';
    }
    else
    {
        return c;
    }
}
// Checks whether characters read identically from left to right and right to left.
string processPalindrom(string s)
{
    // removing unwanted chars
    string processStr1 = "";
    // Key idea: A single mismatched mirrored pair is enough to reject the palindrome.
    for (int i = 0; i < s.length(); i++)
    {
        if (isValidChar(s[i]))
        {
            processStr1.push_back(s[i]);
        }
    }
    // converting all to lower case
    string processStr2 = "";
    for (int j = 0; j < processStr1.length(); j++)
    {
        processStr2.push_back(toLower(processStr1[j]));
    }
    return processStr2;
}
// Checks whether characters read identically from left to right and right to left.
bool checkPalindrom(string &s)
{
    int start = 0;
    int end = s.length() - 1;
    // Key idea: A single mismatched mirrored pair is enough to reject the palindrome.
    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            cout << s[start] << " || " << s[end] << endl;
            return false;
        }
    }
    return true;
}
int main()
{

    string inputStr;
    cout << "Enter string to check palindrome: ";
    cin >> inputStr;
    cout << "Is your string palindrome?: " << checkPalindrom(inputStr) << endl;
}
