#include <bits/stdc++.h>
using namespace std;
void reverseString(string &str, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}
void reverseStringWithSinglePointer(string &str, int start)
{
    int end = str.length() - start - 1;
    if (start > end)
    {
        return;
    }
    swap(str[start], str[end]);
    reverseStringWithSinglePointer(str, start + 1);
}
int main()
{
    string inputStr = "abcde";
    reverseStringWithSinglePointer(inputStr, 0);
    // reverseString(inputStr, 0, inputStr.length() - 1);
    cout << inputStr << endl;
}