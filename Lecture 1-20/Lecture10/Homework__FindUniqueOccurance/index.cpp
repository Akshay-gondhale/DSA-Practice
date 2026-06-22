// -----------------------------------------------------------------------------
// Learning focus: Homework: Find Unique Occurance
// Purpose: Solves Homework: Find Unique Occurance by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/unique-number-of-occurrences/description/
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
    // sorting array internally
    sort(numArr.begin(), numArr.end());
    // First count each value, then compare the counts themselves: the problem
    // requires occurrence totals to be unique, not merely the input values.
    map<int, int> numOccurance;
    for (int i = 0; i < numArr.size(); i++)
    {
        numOccurance[numArr[i]] += 1;
    }
    // vector to store occurances values
    vector<int> occurances;
    for (auto const &pair : numOccurance)
    {
        occurances.push_back(pair.second);
    }
    // sorting for ease
    sort(occurances.begin(), occurances.end());

    for (int i = 0; i < occurances.size() - 1; i++)
    {
        // if found duplicate logging false
        if (occurances[i] == occurances[i + 1])
        {
            cout << "false";
            // return false;
        }
    }
    cout << "true";
}
