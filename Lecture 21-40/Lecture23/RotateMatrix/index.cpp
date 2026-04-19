// https://leetcode.com/problems/rotate-image/description/
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int rowSize = matrix[0].size();
    // running outer loop row size / 2 so to cover all inner circles one by one

    for (int i = 0; i < int(rowSize / 2); i++)
    {
        // running inner loop for row size to shuffle single rows in all sides
        // then it will proceed to next inner circle
        for (int j = i; j < rowSize - i - 1; j++)
        {
            cout << j << endl;
            // swapping top row extreme end elements in circle
            cout << "SWAPPING " << matrix[i][j]
                 << " :: " << matrix[j][rowSize - i - 1] << endl;
            swap(matrix[i][j], matrix[j][rowSize - i - 1]);
            // swapping first and last col's last elem
            cout << "SWAPPING " << matrix[i][j]
                 << " :: " << matrix[rowSize - i - 1][rowSize - j - 1]
                 << endl;
            swap(matrix[i][j], matrix[rowSize - i - 1][rowSize - j - 1]);
            // swapping first and last row's first elem
            cout << "SWAPPING " << matrix[i][j]
                 << " :: " << matrix[rowSize - j - 1][i] << endl;

            swap(matrix[i][j], matrix[rowSize - j - 1][i]);
        }
    }
};
int main()
{
    vector<vector<int>> matrix;
    int matrixSize;
    cout << "Enter size of matrix (eg: 3 for 3x3): ";
    cin >> matrixSize;
    cout << "Enter " << (matrixSize * matrixSize) << " elements for array of " << matrixSize << "x" << matrixSize << " : " << endl;
    for (int row = 0; row < matrixSize; row++)
    {
        vector<int> rowVector;
        for (int column = 0; column < matrixSize; column++)
        {
            int input;
            cin >> input;
            rowVector.push_back(input);
        }
        matrix.push_back(rowVector);
    }
    cout << endl;
    cout << endl;
    cout << "Print matrix:" << endl;
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < matrixSize; column++)
        {
            cout << matrix[row][column] << " ";
        }
        cout << endl;
    }
    rotate(matrix);
    cout << endl;
    cout << "Printing rotated matrix:" << endl;
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < matrixSize; column++)
        {
            cout << matrix[row][column] << " ";
        }
        cout << endl;
    }
}