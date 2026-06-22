// -----------------------------------------------------------------------------
// Learning focus: Reverse String Using Recursion
// Purpose: Performs the Reverse String Using Recursion string transformation or query.
// Core idea: Indices identify characters or word boundaries while the algorithm updates, counts, or reverses the relevant range.
// Complexity note: The main scan is linear in the string length unless repeated searching or erasing causes additional work.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Reverses the requested sequence or range by exchanging characters/elements from opposite ends.
void reverseString(string &str, int start, int end)
{
    // Key idea: Move both boundaries inward after each swap so every pair is processed once.
    if (start > end)
    {
        return;
    }
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}
// Reverses the string recursively using one index; its mirror position is derived from the string length.
void reverseStringWithSinglePointer(string &str, int start)
{
    int end = str.length() - start - 1;
    // Key idea: Stop after reaching the middle, because every character pair has then been swapped exactly once.
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
