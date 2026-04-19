// leetcode problem 186. Its locked needs subscription
#include <iostream>
#include <vector>
using namespace std;

string reversingWordsInString(string str)
{
    vector<string> words;
    string subStr;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            if (subStr.length() > 0)
            {

                words.push_back(subStr);
            }
            subStr = "";
            continue;
        }
        subStr.push_back(str[i]);
    }
    words.push_back(subStr);
    int start = 0;
    int end = words.size() - 1;
    while (start < end)
    {
        swap(words[start], words[end]);
        start++;
        end--;
    }
    string returnStr;
    for (int i = 0; i < words.size(); i++)
    {
        returnStr.append(words[i]);
        returnStr.push_back(' ');
    }
    return returnStr;
}
int main()
{
    string inputStr;
    cout << "Enter a string: " << endl;
    getline(cin, inputStr);
    cout << "You entered: " << inputStr << endl;
    string reversedStr = reversingWordsInString(inputStr);
    cout << "Reversed String: " << reversedStr << endl;
}