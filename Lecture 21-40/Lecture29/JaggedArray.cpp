// -----------------------------------------------------------------------------
// Learning focus: Jagged Array
// Purpose: Demonstrates Jagged Array and explicit dynamic-memory management.
// Core idea: Allocate required rows/elements on the heap, access them through pointers, and release every allocation with matching delete operations.
// Complexity note: Memory usage is proportional to the number of dynamically allocated elements.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// A jagged array (also known as an irregular or ragged array) is a multidimensional array where each individual row can have a different number of columns.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    int *colLengthForEachRow = new int[rows];
    cout << "Enter col length for each individual row: ";
    for (int i = 0; i < rows; i++)
    {
        cin >> colLengthForEachRow[i];
    }
    // initialisation
    int **numArr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        // taking col length from previous array and creating array of same length
        numArr[i] = new int[colLengthForEachRow[i]];
    }

    // taking input
    for (int i = 0; i < rows; i++)
    {
        int colLengthOfRow = colLengthForEachRow[i];
        cout << "Please enter " << colLengthOfRow << " elements for row " << i + 1 << ":" << endl;
        for (int j = 0; j < colLengthOfRow; j++)
        {
            cin >> numArr[i][j];
        }
    }
    cout << endl;
    // printing
    for (int i = 0; i < rows; i++)
    {
        int colLengthOfRow = colLengthForEachRow[i];
        for (int j = 0; j < colLengthOfRow; j++)
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
    delete[] colLengthForEachRow;
}