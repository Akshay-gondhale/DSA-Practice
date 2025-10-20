// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
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