// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// ! NOTE: This approach is optimised by using "Stack". This is better than previous one. But this it can be improved more. Check index3.cpp
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string s)
{
    if (s.length() == 1)
        return s;
    stack<char> uniqueChars;

    for (char i : s)
    {
        if (!uniqueChars.empty() && uniqueChars.top() == i)
            uniqueChars.pop();
        else
            uniqueChars.push(i);
    }

    string str = "";
    while (!uniqueChars.empty())
    {
        str += uniqueChars.top();
        uniqueChars.pop();
    }
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    string input;
    cout << "Enter input string: " << endl;
    getline(cin, input);
    string output = removeDuplicates(input);
    cout << "Output: " << output << endl;
}