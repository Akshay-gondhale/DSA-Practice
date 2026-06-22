// -----------------------------------------------------------------------------
// Learning focus: Binary Search2 In2 DMatrix
// Purpose: Solves Binary Search2 In2 DMatrix by repeatedly narrowing a sorted search range.
// Core idea: Compare the middle element with the required condition and discard the half that cannot contain the answer.
// Complexity note: Binary search takes O(log n) time and O(1) iterative extra space; recursive variants use O(log n) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/search-a-2d-matrix-ii/
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int rowIndex = 0;
    int colIndex = cols - 1;
    while (rowIndex < rows && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
        {
            return true;
        }
        if (element < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    cout << "Printing Matrix: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int keyToFind = 5;
    bool result = searchMatrix(matrix, keyToFind);
    cout << "Result of finding key " << keyToFind << " in matrix is: " << result << endl;
}