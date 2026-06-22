// -----------------------------------------------------------------------------
// Learning focus: Is Palindromee
// Purpose: Checks Is Palindromee by comparing characters from opposite ends.
// Core idea: Advance inward while corresponding normalized characters match; any mismatch disproves the palindrome.
// Complexity note: Time is O(n); iterative code uses O(1) extra space and recursion uses O(n) stack space.
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5&leftPanelTabValue=PROBLEM
#include <iostream>
#include <string>
using namespace std;
// Classifies whether a character is alphanumeric so punctuation and spaces can be ignored.
bool isValidChar(char c)
{
    if ((c >= 'A' && c <= 'z') || (c >= '0' && c <= '9'))
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
bool isPalindrome(string &s)
{
    int start = 0;
    int end = s.length();
    // Key idea: A single mismatched mirrored pair is enough to reject the palindrome.
    while (start < end)
    {
        if (!isValidChar(s[start]))
        {
            // increasing start if not a valid char
            start++;
            continue;
        }
        if (!isValidChar(s[end]))
        {
            // decreasing end if not a valid char
            end--;
            continue;
        }
        if (toLower(s[start]) == toLower(s[end]))
        {
            // if matched increasing start and decreading end
            start++;
            end--;
        }
        else
        {
            // not a palindrome
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
    cout << "Is your string palindrome?: " << isPalindrome(inputStr) << endl;
}
