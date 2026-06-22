// -----------------------------------------------------------------------------
// Learning focus: 2 DCol Wise Input
// Purpose: Demonstrates 2 DCol Wise Input on a two-dimensional matrix.
// Core idea: Nested loops or moving boundaries determine the order in which rows and columns are visited.
// Complexity note: Visiting every matrix entry takes O(rows * columns) time.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    int numArr[3][4];
    cout << "Enter 12 elements for array of 3x4: " << endl;
    for (int column = 0; column < 4; column++)
    {
        for (int row = 0; row < 3; row++)
        {
            cin >> numArr[row][column];
        }
    }
    cout << endl;
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
}