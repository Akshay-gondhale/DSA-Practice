// -----------------------------------------------------------------------------
// Learning focus: index3
// Purpose: Solves index3 by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// * NOTE: This approach is most optimised approach on leetcode
#include <iostream>
using namespace std;

string removeDuplicates(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!ans.empty() && ans.back() == s[i])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}
int main()
{
    string input;
    cout << "Enter input string: " << endl;
    getline(cin, input);
    string output = removeDuplicates(input);
    cout << "Output: " << output << endl;
}