// -----------------------------------------------------------------------------
// Learning focus: Reverse Characters Of Words In String
// Purpose: Performs the Reverse Characters Of Words In String string transformation or query.
// Core idea: Indices identify characters or word boundaries while the algorithm updates, counts, or reverses the relevant range.
// Complexity note: The main scan is linear in the string length unless repeated searching or erasing causes additional work.
// -----------------------------------------------------------------------------
// input = "Hello my name is akshay"
// output = "olleH ym eman si yahska"
#include <iostream>
#include <vector>
using namespace std;
// Reverses the requested sequence or range by exchanging characters/elements from opposite ends.
void reverseWordOnSamePosition(int start, int end, string &input)
{
    // Key idea: Move both boundaries inward after each swap so every pair is processed once.
    while (start < end)
    {
        swap(input[start], input[end]);
        start++;
        end--;
    }
}
int main()
{
    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input);
    int start = 0;
    int end = input.length() - 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            end = i - 1;
            reverseWordOnSamePosition(start, end, input);
            start = i + 1;
            end = input.length() - 1;
        }
    }
    // reversing last word
    reverseWordOnSamePosition(start, end, input);
    cout << input << endl;
}
