// -----------------------------------------------------------------------------
// Learning focus: String Compression
// Purpose: Compresses consecutive runs of equal characters in place.
// Core idea: Read one character group at a time and write the character plus a multi-digit count when needed.
// Complexity note: Time is O(n) and auxiliary space is O(1), excluding the output representation.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/string-compression/description/
#include <iostream>
#include <vector>
using namespace std;
int compress(vector<char> &chars)
{
    string output = "";
    int i = 0, j = 0;
    while (i < chars.size() && j < chars.size())
    {
        if (chars[i] != chars[j])
        {
            output.push_back(chars[i]);
            if (j - i > 1)
            {
                output.append(to_string(j - i));
            }
            i = j;
        }
        j++;
    }
    // processing last character
    if (i != j)
    {
        output.push_back(chars[i]);
        if (j - i > 1)
        {
            output.append(to_string(j - i));
        }
    }
    // removing old
    chars.erase(chars.begin(), chars.end());
    for (int i = 0; i < output.length(); i++)
    {
        chars.push_back(output[i]);
    }
    cout << output << endl;
    return output.length();
}
int main()
{
    string input;
    cout << "Enter a string to compress: " << endl;
    getline(cin, input);
    vector<char> charArr;
    for (int i = 0; i < input.length(); i++)
    {
        charArr.push_back(input[i]);
    }
    compress(charArr);
}