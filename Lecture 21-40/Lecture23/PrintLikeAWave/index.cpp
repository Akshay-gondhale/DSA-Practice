// -----------------------------------------------------------------------------
// Learning focus: Print Like AWave
// Purpose: Demonstrates Print Like AWave on a two-dimensional matrix.
// Core idea: Nested loops or moving boundaries determine the order in which rows and columns are visited.
// Complexity note: Visiting every matrix entry takes O(rows * columns) time.
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/print-like-a-wave_893268
#include <iostream>
#include <vector>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArr(vector<int> numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
// Prints matrix columns in alternating directions to form a vertical wave.
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> output;
    // Key idea: Column parity chooses top-to-bottom or bottom-to-top traversal.
    for (int i = 0; i < mCols; i++)
    {
        if (i & 1)
        {
            // print from bottom to top
            for (int j = nRows - 1; j >= 0; j--)
            {
                output.push_back(arr[j][i]);
            }
        }
        else
        {
            // print from top to bottom
            for (int j = 0; j < nRows; j++)
            {
                output.push_back(arr[j][i]);
            }
        }
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

    vector<int> output = wavePrint(numArr, nRows, nCols);
    cout << "Printing output: ";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}
