// https://leetcode.com/problems/reverse-string/description/
#include <iostream>
#include <vector>

using namespace std;
void printArr(vector<char> &stringChars)
{
    for (int i = 0; i < stringChars.size(); i++)
    {
        cout << stringChars[i] << " ";
    }
    cout << endl;
}
void reverseString(vector<char> &stringChars)
{
    int start = 0;
    int end = stringChars.size() - 1;
    while (start < end)
    {
        swap(stringChars[start++], stringChars[end--]);
    }
}
int main()
{
    vector<char> stringChars;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter characters: ";
    for (int i = 0; i < size; i++)
    {
        char input;
        cin >> input;
        stringChars.push_back(input);
    }
    cout << "You entered: ";
    printArr(stringChars);
    reverseString(stringChars);
    cout << "Reversed string: ";
    printArr(stringChars);
}