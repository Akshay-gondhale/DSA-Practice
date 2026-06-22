// -----------------------------------------------------------------------------
// Learning focus: Replace Spaces
// Purpose: Performs the Replace Spaces string transformation or query.
// Core idea: Indices identify characters or word boundaries while the algorithm updates, counts, or reverses the relevant range.
// Complexity note: The main scan is linear in the string length unless repeated searching or erasing causes additional work.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/replace-spaces_1172172
// Note there are two approaches for this -
// one is simply creating another string which have space complexity O(n)
// second modifying existing string. Below implementation is for second tough approach whos space complexity is O(1);
#include <iostream>
using namespace std;
string replaceSpaces(string &str)
{
    int spacesCount = 0;
    int lastStrIndex = str.length() - 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            spacesCount++;
        }
    }
    for (int i = 0; i < spacesCount; i++)
    {
        str.append("  ");
    }

    int j = str.length() - 1;
    while (lastStrIndex < j)
    {
        if (str[lastStrIndex] == ' ')
        {
            str[j] = '0';
            str[j - 1] = '4';
            str[j - 2] = '@';
            lastStrIndex--;
            j = j - 3;
            continue;
        }
        swap(str[lastStrIndex], str[j]);
        lastStrIndex--;
        j--;
    }
    str.append(";");
    return str;
}
int main()
{
    string str;
    cout << "Enter your string here: " << endl;
    getline(cin, str);
    string output = replaceSpaces(str);
    cout << "Output: " << output << endl;
}