// -----------------------------------------------------------------------------
// Learning focus: Checking Palindrome Using Recursion
// Purpose: Demonstrates Checking Palindrome Using Recursion and shows the data flow through a complete example.
// Core idea: Follow the helper functions first, then main(), which prepares input and displays the result.
// Complexity note: Complexity depends on the loops and helper functions identified below.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Checks whether characters read identically from left to right and right to left.
bool isPalindrom(string &str, int start)
{
    int end = str.length() - start - 1;
    // Key idea: A single mismatched mirrored pair is enough to reject the palindrome.
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return isPalindrom(str, start + 1);
}
int main()
{
    string inputStr = "abceba";
    bool result = isPalindrom(inputStr, 0);
    cout << result << endl;
}
