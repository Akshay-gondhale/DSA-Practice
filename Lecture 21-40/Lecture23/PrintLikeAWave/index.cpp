// https://www.naukri.com/code360/problems/print-like-a-wave_893268
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
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> output;
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