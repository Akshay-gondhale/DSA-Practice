// -----------------------------------------------------------------------------
// Learning focus: Binary Search In2 DMatrix
// Purpose: Solves Binary Search In2 DMatrix by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/search-a-2d-matrix/description/
#include <iostream>
#include <vector>
using namespace std;
// Searches a sorted range by comparing its middle value with the target.
bool binarySearch(vector<vector<int>> &matrix, int target)
{
    int rowsNum = matrix.size();
    int colsNum = matrix[0].size();
    int start = 0;
    int end = rowsNum * colsNum - 1;

    // Choose the middle index with an overflow-safe formula before deciding which half remains relevant.
    int mid = start + (end - start) / 2;
    // Key idea: Discard the half that cannot contain the key; this halves the remaining search space each step.
    while (start <= end)
    {
        cout << "MID: " << mid << " || START: " << start << " || END: " << end << endl;

        // dividing mid value by total number of columns will give you row
        // number of mid element eg: mid of 15 will be 7 and 7 / 4 cols = 1
        // i.e. mid will be in 1 index row
        // int midRow = mid / colsNum;
        // taking mode of mid value by total number of columns will give you
        // col number of mid element eg: mid of 15 will be 7 and 7 % 4 cols
        // = 3 i.e. mid will be in 3 index col
        // int midCol = mid % colsNum;
        int element = matrix[mid / colsNum][mid % colsNum];

        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        // Choose the middle index with an overflow-safe formula before deciding which half remains relevant.
        mid = start + (end - start) / 2;
    }
    return 0;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3}};
    cout << "Printing Matrix: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int keyToFind = 3;
    bool result = binarySearch(matrix, keyToFind);
    cout << "Result of finding key " << keyToFind << " in matrix is: " << result << endl;
}
