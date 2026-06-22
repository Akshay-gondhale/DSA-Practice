// -----------------------------------------------------------------------------
// Learning focus: Remove All Occurrances Of Substring
// Purpose: Performs the Remove All Occurrances Of Substring string transformation or query.
// Core idea: Indices identify characters or word boundaries while the algorithm updates, counts, or reverses the relevant range.
// Complexity note: The main scan is linear in the string length unless repeated searching or erasing causes additional work.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
#include <iostream>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main()
{
    string input, part;
    cout << "Enter a string: " << endl;
    getline(cin, input);
    cout << "Enter part to remove: " << endl;
    getline(cin, part);
    string output = removeOccurrences(input, part);
    cout << "Output post removing occurrences: " << output << endl;
}