// input = "Hello my name is akshay"
// output = "olleH ym eman si yahska"
#include <iostream>
#include <vector>
using namespace std;
void reverseWordOnSamePosition(int start, int end, string &input)
{
    while (start < end)
    {
        swap(input[start], input[end]);
        start++;
        end--;
    }
}
int main()
{
    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input);
    int start = 0;
    int end = input.length() - 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            end = i - 1;
            reverseWordOnSamePosition(start, end, input);
            start = i + 1;
            end = input.length() - 1;
        }
    }
    // reversing last word
    reverseWordOnSamePosition(start, end, input);
    cout << input << endl;
}