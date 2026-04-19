// https://leetcode.com/problems/spiral-matrix/
#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int> numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> output;
    int leftToRight = 0;                // pointer for left to right
    int topToBottom = matrix[0].size(); // pointer for top to bottom
    int rightToLeft = matrix.size();    // pointer for right to left
    int bottomToTop = 0;                // pointer for bottom to top

    int rows = matrix.size();
    int cols = matrix[0].size();
    int totalElements = rows * cols;
    // running loop until loop overlaps
    while (output.size() < totalElements)
    {
        // left to right
        for (int i = bottomToTop; (i < topToBottom && output.size() < totalElements); i++)
        {
            output.push_back(matrix[leftToRight][i]);
        }
        // after completing incrementing
        leftToRight++;

        // top to bottom
        for (int j = leftToRight; (j < rightToLeft && output.size() < totalElements); j++)
        {
            output.push_back(matrix[j][topToBottom - 1]);
        }
        // after completing decrementing
        topToBottom--;

        // right to left
        for (int k = topToBottom - 1; (k >= bottomToTop && output.size() < totalElements); k--)
        {
            output.push_back(matrix[rightToLeft - 1][k]);
        }
        // after completing decrementing
        rightToLeft--;

        // bottom to top
        for (int l = rightToLeft - 1; (l >= leftToRight && output.size() < totalElements); l--)
        {
            output.push_back(matrix[l][bottomToTop]);
        }
        // after completing incrementing
        bottomToTop++;
    }
    return output;
}
int main()
{
    int nRows, nCols;
    cout << "Enter number of rows: ";
    cin >> nRows;
    cout << "Enter number of cols: ";
    cin >> nCols;
    cout << "Enter " << nRows << "x" << nCols << " array elements: " << endl;
    vector<vector<int>> numArr;
    for (int i = 0; i < nRows; i++)
    {
        vector<int> row;
        for (int j = 0; j < nCols; j++)
        {
            int input;
            cin >> input;
            row.push_back(input);
        }
        numArr.push_back(row);
    }
    cout << "Print 2D array:" << endl;
    for (int row = 0; row < nRows; row++)
    {
        for (int column = 0; column < nCols; column++)
        {
            cout << numArr[row][column] << " ";
        }
        cout << endl;
    }

    vector<int> output = spiralOrder(numArr);
    cout << "Printing output: ";
    printArr(output);
}