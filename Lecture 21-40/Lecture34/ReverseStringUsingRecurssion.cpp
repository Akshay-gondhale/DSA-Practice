// -----------------------------------------------------------------------------
// Learning focus: Reverse String Using Recursion
// Purpose: Performs the Reverse String Using Recursion string transformation or query.
// Core idea: Indices identify characters or word boundaries while the algorithm updates, counts, or reverses the relevant range.
// Complexity note: The main scan is linear in the string length unless repeated searching or erasing causes additional work.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void reverseString(string &str, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}
void reverseStringWithSinglePointer(string &str, int start)
{
    int end = str.length() - start - 1;
    if (start > end)
    {
        return;
    }
    swap(str[start], str[end]);
    reverseStringWithSinglePointer(str, start + 1);
}
int main()
{
    string inputStr = "abcde";
    reverseStringWithSinglePointer(inputStr, 0);
    // reverseString(inputStr, 0, inputStr.length() - 1);
    cout << inputStr << endl;
}