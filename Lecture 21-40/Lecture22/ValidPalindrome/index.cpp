// https : // leetcode.com/problems/valid-palindrome/description/
#include <iostream>
#include <string>
using namespace std;
bool isValidChar(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {

        // eg: "C" ASCII is 67
        // "A" ASCII is 65
        // "a" ASCII is 97
        // 67 - 65 + 97 => 99
        // 99 is ASCII of 'c
        return c - 'A' + 'a';
    }
    else
    {
        return c;
    }
}
string processPalindrom(string s)
{
    // removing unwanted chars
    string processStr1 = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isValidChar(s[i]))
        {
            processStr1.push_back(s[i]);
        }
    }
    // converting all to lower case
    string processStr2 = "";
    for (int j = 0; j < processStr1.length(); j++)
    {
        processStr2.push_back(toLower(processStr1[j]));
    }
    return processStr2;
}
bool checkPalindrom(string &s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            cout << s[start] << " || " << s[end] << endl;
            return false;
        }
    }
    return true;
}
int main()
{

    string inputStr;
    cout << "Enter string to check palindrome: ";
    cin >> inputStr;
    cout << "Is your string palindrome?: " << checkPalindrom(inputStr) << endl;
}