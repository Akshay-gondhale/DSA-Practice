// https://leetcode.com/problems/permutation-in-string/description/
// * NOTE: This is the most optimised approach on leetcode.
#include <iostream>
#include <unordered_map>
using namespace std;
void printingMap(unordered_map<char, int> inputMap)
{
    for (auto i : inputMap)
    {
        cout << i.first << " :: " << i.second << endl;
    }
}
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
    // checking permutation in string 2
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
