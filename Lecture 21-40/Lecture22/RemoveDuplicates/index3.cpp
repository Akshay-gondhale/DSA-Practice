// -----------------------------------------------------------------------------
// Learning focus: index3
// Purpose: Solves index3 by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// * NOTE: This approach is most optimised approach on leetcode
#include <iostream>
using namespace std;

// Compacts repeated values so only one representative remains in the result.
string removeDuplicates(string s)
{
    string ans = "";
    // Key idea: A write index marks the next retained position while the read index scans for a new value.
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
