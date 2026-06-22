// -----------------------------------------------------------------------------
// Learning focus: Remove Duplicates
// Purpose: Solves Remove Duplicates by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// ! NOTE: This approach works but its not optimised and give time limit exceed error.
#include <iostream>
using namespace std;

string removeDuplicates(string s)
{
    int i = 0;
    while (s.length() > 0 && i + 1 < s.length())
    {
        if (s[i] == s[i + 1])
        {
            string removingString = "";
            removingString.push_back(s[i]);
            removingString.push_back(s[i]);
            s.erase(s.find(removingString), 2);
            i = 0;
            cout << "After: " << s << endl;
            continue;
        }
        i++;
    }
    return s;
}
int main()
{
    string input;
    cout << "Enter input string: " << endl;
    getline(cin, input);
    string output = removeDuplicates(input);
    cout << "Output: " << output << endl;
}