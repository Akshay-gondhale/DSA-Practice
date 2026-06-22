// -----------------------------------------------------------------------------
// Learning focus: Dynamic2 DArray
// Purpose: Demonstrates Dynamic2 DArray on a two-dimensional matrix.
// Core idea: Nested loops or moving boundaries determine the order in which rows and columns are visited.
// Complexity note: Visiting every matrix entry takes O(rows * columns) time.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // initializing
    int **numArr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        numArr[i] = new int[cols];
    }
    // taking input
    cout << "Please enter " << rows << "x" << cols << " matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> numArr[i][j];
        }
    }

    // printing
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << numArr[i][j] << " ";
        }

        cout << endl;
    }

    // cleanup
    for (int i = 0; i < rows; i++)
    {
        delete[] numArr[i];
    }
    delete[] numArr;
}