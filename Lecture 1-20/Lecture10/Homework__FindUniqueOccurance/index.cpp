// https://leetcode.com/problems/unique-number-of-occurrences/description/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
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
    // creating map to store occurances
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