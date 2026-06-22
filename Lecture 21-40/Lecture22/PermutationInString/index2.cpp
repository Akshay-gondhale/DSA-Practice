// -----------------------------------------------------------------------------
// Learning focus: Permutation In String Using A Hash Map
// Copies the required character counts for each candidate window, then removes
// matched characters from that copy. An empty map means the window matched.
// Rebuilding the map for each window makes this approach roughly O(|s1|*|s2|).
// -----------------------------------------------------------------------------
// this is implementing solution using map
// ! NOTE: surprisingly this works slower than other method. other method is fast because of fixed size of array as 26
#include <iostream>
#include <unordered_map>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printingMap(unordered_map<char, int> inputMap)
{
    for (auto i : inputMap)
    {
        cout << i.first << " :: " << i.second << endl;
    }
}
// Tests each candidate window against a fresh copy of s1's frequency map.
bool checkPermutationInSting(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return false;
    }
    unordered_map<char, int> charCounts1;
    for (int i = 0; i < s1.length(); i++)
    {
        char s1Char = s1[i];
        if (charCounts1.count(s1Char))
        {
            // increamenting if already present
            charCounts1[s1Char]++;
        }
        else
        {
            // creating if not present already
            charCounts1[s1Char] = 1;
        }
    }
    // Consuming matching characters from the copied map avoids caring about
    // their order within the current window.
    for (int i = 0; i < s2.length() - s1.length() + 1; i++)
    {
        unordered_map<char, int> copyCharCounts1(charCounts1);
        for (int j = i; j < i + s1.length(); j++)
        {
            if (!copyCharCounts1.count(s2[j]))
            {
                // breaking directly without cheking next chars if found mismatch
                break;
            }
            if (copyCharCounts1[s2[j]] - 1 > 0)
            {
                copyCharCounts1[s2[j]]--;
            }
            else
            {
                copyCharCounts1.erase(s2[j]);
            }
        }
        if (copyCharCounts1.empty())
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string s1, s2;
    cout << "Enter string s1: " << endl;
    getline(cin, s1);
    cout << "Enter string s2: " << endl;
    getline(cin, s2);
    bool output = checkPermutationInSting(s1, s2);
    cout << "Output: " << output << endl;
}
