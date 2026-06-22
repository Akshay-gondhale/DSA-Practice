// -----------------------------------------------------------------------------
// Learning focus: Get Max Occuring Char
// Purpose: Performs the Get Max Occuring Char string transformation or query.
// Core idea: Indices identify characters or word boundaries while the algorithm updates, counts, or reverses the relevant range.
// Complexity note: The main scan is linear in the string length unless repeated searching or erasing causes additional work.
// -----------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
#include <iostream>
using namespace std;
// Counts character frequencies and returns the character with the largest count.
char getMaxOccuringChar(string &s)
{
    int charArr[26] = {0};
    // Key idea: Convert a character to an array index so each occurrence updates its frequency in constant time.
    for (int i = 0; s[i] != '\0'; i++)
    {
        int arrIndex;
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // for lower chars
            arrIndex = s[i] - 'a';
        }
        else
        {
            // for uppar chars
            arrIndex = s[i] - 'A';
        }
        charArr[arrIndex]++;
    }
    int maxOcc = -1;
    int maxIndex = -1;
    for (int i = 0; i < 26; i++)
    {
        if (charArr[i] > maxOcc)
        {
            maxOcc = charArr[i];
            maxIndex = i;
        }
    }
    return 'a' + maxIndex;
}
int main()
{
    string input;
    cout << "Enter a word to check: " << endl;
    cin >> input;
    char output = getMaxOccuringChar(input);
    cout << output << endl;
}
