#include <bits/stdc++.h>
using namespace std;
bool isPalindrom(string &str, int start)
{
    int end = str.length() - start - 1;
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return isPalindrom(str, start + 1);
}
int main()
{
    string inputStr = "abceba";
    bool result = isPalindrom(inputStr, 0);
    cout << result << endl;
}