// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include <bits/stdc++.h>
using namespace std;

void findLettersCombination(string digits, int index, string output, vector<string> &ans, string mapping[])
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    // index value of string will return character. And lets say if it returns '2' then achii value of character 2 might be something else and
    // while casting ans storing it, it may become like 57 so
    // substracting character '0' from it then it will give actual number while transpiling
    int currentDigit = digits[index] - '0';
    string digitLetterMapping = mapping[currentDigit];
    for (int i = 0; i < digitLetterMapping.length(); i++)
    {
        output.push_back(digitLetterMapping[i]);
        findLettersCombination(digits, index + 1, output, ans, mapping);
        output.pop_back();
    }
}
int main()
{
    string inputString = "23";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    if (inputString.length() == 0)
        return;
    vector<string> ans;
    findLettersCombination(inputString, 0, output, ans, mapping);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}