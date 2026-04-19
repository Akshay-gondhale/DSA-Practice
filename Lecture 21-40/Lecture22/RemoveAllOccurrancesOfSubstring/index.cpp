// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
#include <iostream>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main()
{
    string input, part;
    cout << "Enter a string: " << endl;
    getline(cin, input);
    cout << "Enter part to remove: " << endl;
    getline(cin, part);
    string output = removeOccurrences(input, part);
    cout << "Output post removing occurrences: " << output << endl;
}