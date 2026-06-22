// -----------------------------------------------------------------------------
// Learning focus: Checking Palindrome Using Recursion
// Purpose: Demonstrates Checking Palindrome Using Recursion and shows the data flow through a complete example.
// Core idea: Follow the helper functions first, then main(), which prepares input and displays the result.
// Complexity note: Complexity depends on the loops and helper functions identified below.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
bool isPalindrom(string &str, int start)
{
    int end = str.length() - start - 1;
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