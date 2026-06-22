// -----------------------------------------------------------------------------
// Learning focus: Reverse The Array
// Purpose: Demonstrates Reverse The Array using in-place element swaps.
// Core idea: Move indices from the relevant ends or neighboring positions and swap each required pair exactly once.
// Complexity note: Time is O(n) and auxiliary space is O(1).
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/reverse-the-array_1262298?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArr(vector<int> &numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
// Reverses the requested sequence or range by exchanging characters/elements from opposite ends.
void reverseTheArray(vector<int> &numArr, int m)
{
    int start = m + 1;
    int end = numArr.size() - 1;
    // Key idea: Move both boundaries inward after each swap so every pair is processed once.
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
