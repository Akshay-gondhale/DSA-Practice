// -----------------------------------------------------------------------------
// Learning focus: Reversing String
// Purpose: Performs the Reversing String string transformation or query.
// Core idea: Indices identify characters or word boundaries while the algorithm updates, counts, or reverses the relevant range.
// Complexity note: The main scan is linear in the string length unless repeated searching or erasing causes additional work.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/reverse-string/description/
#include <iostream>
#include <vector>

using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArr(vector<char> &stringChars)
{
    for (int i = 0; i < stringChars.size(); i++)
    {
        cout << stringChars[i] << " ";
    }
    cout << endl;
}
// Reverses the requested sequence or range by exchanging characters/elements from opposite ends.
void reverseString(vector<char> &stringChars)
{
    int start = 0;
    int end = stringChars.size() - 1;
    // Key idea: Move both boundaries inward after each swap so every pair is processed once.
    while (start < end)
    {
        swap(stringChars[start++], stringChars[end--]);
    }
}
int main()
{
    vector<char> stringChars;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter characters: ";
    for (int i = 0; i < size; i++)
    {
        char input;
        cin >> input;
        stringChars.push_back(input);
    }
    cout << "You entered: ";
    printArr(stringChars);
    reverseString(stringChars);
    cout << "Reversed string: ";
    printArr(stringChars);
}
