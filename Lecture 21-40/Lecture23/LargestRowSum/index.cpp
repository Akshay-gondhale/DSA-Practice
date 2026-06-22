// -----------------------------------------------------------------------------
// Learning focus: Largest Row Sum
// Purpose: Demonstrates Largest Row Sum on a two-dimensional matrix.
// Core idea: Nested loops or moving boundaries determine the order in which rows and columns are visited.
// Complexity note: Visiting every matrix entry takes O(rows * columns) time.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    int numArr[3][4];
    cout << "Enter 12 elements for array of 3x4: " << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            cin >> numArr[row][column];
        }
    }
    cout << endl;
    cout << "Print 2D array:" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            cout << numArr[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int largestSum = 0;
    int largestSumIndex = -1;
    cout << "Printing row wise sum: " << endl;
    // Reset sum for every row, then retain both the largest total and the row
    // index that produced it.
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += numArr[i][j];
            cout << numArr[i][j] << " ";
        }
        cout << ": " << sum << endl;
        if (largestSum < sum)
        {
            largestSum = sum;
            largestSumIndex = i;
        }
    }
    cout << endl;
    cout << "Largest row sum is at index: " << largestSumIndex;
}
