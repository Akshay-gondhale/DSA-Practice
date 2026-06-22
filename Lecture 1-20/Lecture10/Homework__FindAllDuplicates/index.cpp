// -----------------------------------------------------------------------------
// Learning focus: Homework: Find All Duplicates
// Purpose: Solves Homework: Find All Duplicates by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> numArr;
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        int inputNum;
        cin >> inputNum;
        numArr.push_back(inputNum);
    }
    // Sorting places equal values next to one another, so duplicates can be
    // detected with a single adjacent-pair scan.
    sort(numArr.begin(), numArr.end());
    vector<int> repeatedNums;
    for (int i = 0; i < numArr.size() - 1; i++)
    {
        if (numArr[i] == numArr[i + 1])
        {
            repeatedNums.push_back(numArr[i]);
        }
    }
    printArray(repeatedNums);
}
