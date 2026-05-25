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