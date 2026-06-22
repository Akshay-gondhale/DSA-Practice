// -----------------------------------------------------------------------------
// Learning focus: index2
// Purpose: Solves index2 by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// ! NOTE: This approach is optimised by using "Stack". This is better than previous one. But this it can be improved more. Check index3.cpp
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Compacts repeated values so only one representative remains in the result.
string removeDuplicates(string s)
{
    // Key idea: A write index marks the next retained position while the read index scans for a new value.
    if (s.length() == 1)
        return s;
    stack<char> uniqueChars;

    for (char i : s)
    {
        if (!uniqueChars.empty() && uniqueChars.top() == i)
            uniqueChars.pop();
        else
            uniqueChars.push(i);
    }

    string str = "";
    while (!uniqueChars.empty())
    {
        str += uniqueChars.top();
        uniqueChars.pop();
    }
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    string input;
    cout << "Enter input string: " << endl;
    getline(cin, input);
    string output = removeDuplicates(input);
    cout << "Output: " << output << endl;
}
