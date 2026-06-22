// -----------------------------------------------------------------------------
// Learning focus: Reverse The Array
// Purpose: Demonstrates Reverse The Array using in-place element swaps.
// Core idea: Move indices from the relevant ends or neighboring positions and swap each required pair exactly once.
// Complexity note: Time is O(n) and auxiliary space is O(1).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/reverse-the-array_1262298?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printArr(vector<int> &numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
void reverseTheArray(vector<int> &numArr, int m)
{
    int start = m + 1;
    int end = numArr.size() - 1;
    while (start < end)
    {
        swap(numArr[start], numArr[end]);
        start++;
        end--;
    }
    printArr(numArr);
}
int main()
{
    vector<int> numArr;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        numArr.push_back(input);
    }
    int m;
    cout << "Enter index to rotate from: " << endl;
    cin >> m;
    reverseTheArray(numArr, m);
}